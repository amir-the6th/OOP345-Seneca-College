/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-04-10            ///
|*******************************************|
|**********  Final Project - MS3  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>
#include <algorithm>

namespace sdds{
	typedef std::string string;
	class Utilities {
		size_t m_widthField{ 1 }; //specifies the length of the token extracted
		static char m_delimiter; //separates the tokens in any given std::string object
	public:
		void setFieldWidth(size_t newWidth); //sets the field width of the current object to the value of parameter
		size_t getFieldWidth() const; //returns the field width of the current object
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more); //extracts a token from str referred to by the first param
		static void setDelimiter(char newDelimiter); //sets the delimiter for this class to the character received
		static char getDelimiter(); //returns the delimiter for this class
	};
}
#endif