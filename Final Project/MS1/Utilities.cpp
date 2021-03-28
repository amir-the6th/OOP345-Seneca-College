/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-27            ///
|*******************************************|
|**********  Final Project - MS1  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/
#include "Utilities.h"

namespace sdds {
	char Utilities::m_delimiter = ','; //just for initialization

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string token{};
		size_t first_pos = next_pos;
		next_pos = str.find(m_delimiter, first_pos);

		/* for self documentation: string::npos is a constant (probably -1) 
		   representing a non-position. It's returned by method "find" when 
		   the pattern was not found.
		*/
		if (first_pos == next_pos) {
			more = false;
			throw "No token found!";
		}
		else if (next_pos != string::npos) { //found
			token = str.substr(first_pos, next_pos - first_pos);

			//m_widthField = m_widthField < token.length() ? token.length() : m_widthField;
			m_widthField = std::max(token.length(), m_widthField); //std::max returns the largest of token.length() and 
																  //m_widthField. If both are equivalent, token.length() is returned.
			more = true;
		}
		else if (next_pos == string::npos) { //not found
			token = str.substr(first_pos);
			m_widthField = std::max(token.length(), m_widthField);
			more = false;
		}
		next_pos++;
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}
