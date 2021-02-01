/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-01-31            ///
|*******************************************|
|*********  Workshop 2 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "StringSet.h"

namespace sdds {
	void sdds::StringSet::setEmpty() {
		s_noCurrentStrings = 0u;
		s_strings = nullptr;
	}
	StringSet::StringSet() {
		setEmpty();
	}
	StringSet::~StringSet() {
		delete[] s_strings;
	}
	StringSet::StringSet(const char* fileName) : s_noCurrentStrings{ 0 }, s_strings{ nullptr } {
		if (!(fileName == nullptr)) {
			std::ifstream fs(fileName);
			std::string tempString;

			if (fs.is_open()) {
				while ( !(fs.eof()) ) { //continue the loop until it reaches the end of the file
					getline(fs, tempString, ' ');
					s_noCurrentStrings++;
				}
				fs.clear();	//allow the stream to start input operations - removes the flag and sets it for ouput operations
				fs.seekg(0); //set the pointer to the beginning of the file

				s_strings = new std::string[s_noCurrentStrings];
				size_t i{ 0 };
				while (getline(fs, tempString, ' ')) {
					s_strings[i] = tempString;
					i++;
				}
			}
		}
		else {
			setEmpty();
		}
	}
	StringSet::StringSet(const StringSet& SS) {
		s_strings = nullptr;
		*this = SS;
	}
	StringSet::StringSet(StringSet&& SS) noexcept { //added "noexcept" to prevent C26439 warning
		*this = std::move(SS);
	}
	StringSet& StringSet::operator=(StringSet&& SS) noexcept { //added "noexcept" to prevent C26439 warning
		if (this != &SS) {
			s_noCurrentStrings = SS.s_noCurrentStrings;
			SS.s_noCurrentStrings = 0u;

			s_strings = SS.s_strings;
			SS.s_strings = nullptr;
		}
		return *this;
	}
	StringSet& StringSet::operator=(const StringSet& SS) {
		if (this != &SS) {
			s_noCurrentStrings = SS.s_noCurrentStrings;
			delete[] s_strings;
			s_strings = new std::string[s_noCurrentStrings];
			for (size_t i = 0u; i < s_noCurrentStrings; i++) {
				s_strings[i] = SS.s_strings[i];
			}
		}
		return *this;
	}
	size_t StringSet::size()
	{
		return s_noCurrentStrings;
	}
	std::string StringSet::operator[](size_t index) {
		std::string empty = "";
		return index < s_noCurrentStrings ? s_strings[index] : empty;
	}
}
