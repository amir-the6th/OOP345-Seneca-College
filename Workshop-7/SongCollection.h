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

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

namespace sdds {
	typedef std::string string;
	struct Song {
		string artist{}, title{}, album{};
		double m_price{};
		size_t releaseYear{}, length{};
	};
	class SongCollection {
		std::vector<Song> songs;
	public:
		SongCollection(string filename);
		void display(std::ostream& out) const;
		void sort(string accordingTo);
		void cleanAlbum();
		bool inCollection(string artist) const;
		std::list<Song> getSongsForArtist(string artist) const;
		string trim(string& str);
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
} 
#endif