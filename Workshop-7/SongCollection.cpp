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
					catch (std::invalid_argument&) {
						song.releaseYear = 0;
					}
					str.erase(0, 5);

					//LENGTH
					length = str.substr(0, 5);
					song.length = std::stoi(trim(length));
					str.erase(0, 5);

					//PRICE
					price = str.substr(0, 5);
					song.m_price = std::stod(trim(price));
					str.erase(0, 5);

					songs.push_back(song); //push the song data to the songs vector
				}
			}
			file.close();
		}
	}
	void SongCollection::display(std::ostream& out) const {
		std::for_each(songs.begin(), songs.end(), [&out](const Song theSong) { out << theSong << std::endl;});
		size_t totalListeningTime = std::accumulate(songs.begin(), songs.end(), (size_t)0,
			[](size_t total, const Song song) {
				return total + song.length;
			});
		size_t hour{ totalListeningTime / 3600 }, 
			min{ (totalListeningTime % 3600) / 60 }, 
			sec{ totalListeningTime % 60 };
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::setw(77) << std::right << "Total Listening Time: " << hour << ":" << min << ":" << sec << " |" << std::endl;
	}
	void SongCollection::sort(string accordingTo) {
		if (accordingTo == "title") {
			std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) -> bool {
					return s1.title < s2.title;
				}
			);
		}
		else if (accordingTo == "length") {
			std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) -> bool {
				return s1.length < s2.length;
				}
			);
		}
		else if (accordingTo == "album") {
			std::sort(songs.begin(), songs.end(), [](Song s1, Song s2) -> bool {
				return s1.album < s2.album;
				}
			);
		}
	}
	void SongCollection::cleanAlbum() {
		std::transform(songs.begin(), songs.end(), songs.begin(), [=](Song& sng) {
			sng.album = sng.album == "[None]" ? "" : sng.album;
			return sng;
		});
	}
	bool SongCollection::inCollection(string artist) const {
		return std::any_of(songs.begin(), songs.end(), [artist](Song sng) -> bool {
			return sng.artist == artist;
		});
	}
	std::list<Song> SongCollection::getSongsForArtist(string artist) const {
		size_t count = std::count_if(songs.begin(), songs.end(), [artist](const Song song) -> bool {
			return song.artist == artist;
		});

		std::list<Song> songsWithArtist(count);
		std::copy_if(songs.begin(), songs.end(), songsWithArtist.begin(), [artist](const Song song) -> bool {
			return song.artist == artist;
		});

		return songsWithArtist;
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
			<< std::fixed << std::setprecision(2) << theSong.m_price << " |"
			<< std::setfill(' ');
		return out;
	}
} 
