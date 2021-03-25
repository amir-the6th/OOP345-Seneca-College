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
#include <string>

namespace sdds {
	typedef std::string string;
	struct Song {
	private:
		string s_artist{};
		string s_title{};
		string s_album{};
		double s_price{};
		size_t s_releaseYear{};
		size_t s_length{};
	};
	class SongCollection {
		Song song;
	public:
		SongCollection(string file);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif