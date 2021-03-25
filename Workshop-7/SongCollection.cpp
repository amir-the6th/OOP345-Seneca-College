/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-25            ///
|*******************************************|
|*********  Workshop 7 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(string filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "ERROR: Cannot open the file.\n";
		}
		else {
			string str, title, artist, album, year, length, price;
			Song song;
			while(file){
				std::getline(file, str, '\n');

				if (!str.empty()) {
					//TITLE
					title = str.substr(0, 25);
					song.title = trim(title);
					str.erase(0, 25);

					//ARTIST
					artist = str.substr(0, 25);
					song.artist = trim(artist);
					str.erase(0, 25);

					//ALBUM
					album = str.substr(0, 25);
					song.album = trim(album);
					str.erase(0, 25);

					//YEAR
					year = str.substr(0, 5);
					try {
						song.releaseYear = std::stoi(trim(year));
					}
					catch (std::invalid_argument) {
						song.releaseYear = 0;
					}
					str.erase(0, 5);

					//LENGTH
					length = str.substr(0, 5);
					song.length = std::stoi(trim(length));
					str.erase(0, 5);

					//PRICE
					price = str.substr(0, 5);
					song.price = std::stod(trim(price));
					str.erase(0, 5);

					songs.push_back(song); //push the song data to the songs vector
				}
			}
			file.close();
		}
	}
	void SongCollection::display(std::ostream& out) const {
		std::for_each(songs.begin(), songs.end(), [&out](const Song theSong) { out << theSong << std::endl;});
	}
	string SongCollection::trim(string& str) {
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
		return str;
	}
	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		string tempYear{ theSong.releaseYear == 0 ? "" : std::to_string(theSong.releaseYear) }; //if year is unavailable (set to 0), show nothing
		out << "| " << std::left << std::setw(20) << theSong.title << " | "
			<< std::left << std::setw(15) << theSong.artist << " | "
			<< std::left << std::setw(20) << theSong.album << " | "
			<< std::setw(6) << std::right << tempYear  << " | "
			<< (theSong.length % 3600) / 60 << ":" << std::setw(2) << std::setfill('0') << theSong.length % 60 << " | "
			<< std::fixed << std::setprecision(2) << theSong.price << " |"
			<< std::setfill(' ');
		return out;
	}
}
