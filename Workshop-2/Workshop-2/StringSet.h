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

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <string>

namespace sdds {
	class StringSet {
		size_t s_noCurrentStrings; //number of strings currently stored
		std::string* s_strings;	//dynamically allocated array of strings
		void setEmpty(); //set to empty state
	public:
		StringSet(); //default constructor
		~StringSet();// destructor
		StringSet(const char*);	//1-arg constructor: read file and count strings -> load them to array
		StringSet(const StringSet&); //copy constructor
		StringSet(StringSet&&) noexcept;	//move constructor
		StringSet& operator=(StringSet&&) noexcept; // move assignment operator
		StringSet& operator=(const StringSet&); // copy assignment operator
		size_t size(); //number of strings stored in the current object
		std::string operator[](size_t);	//a copy of the string at the index received as the parameter
	};
}
#endif