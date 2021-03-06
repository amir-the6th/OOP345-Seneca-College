/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-06            ///
|*******************************************|
|*********  Workshop 5 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "SpellChecker.h"
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			size_t i{ 0 };
			string line, badWord;
			do {
				
				std::getline(file, line);

				//BAD WORD
				badWord = line.substr(0, line.find(' '));
				badWord.erase(0, badWord.find_first_not_of(' '));
				badWord.erase(badWord.find_last_not_of(' ') + 1);

				m_badWords[i] = badWord;
				line.erase(0, line.find(' ') + 1);

				//GOOD WORD
				line.erase(0, line.find_first_not_of(' '));
				line.erase(line.find_last_not_of(' ') + 1);
				m_goodWords[i] = line;
			} while (file && i++ < MAX_WORDS);
		}
	}
	void SpellChecker::operator()(std::string& text) {
		size_t i{ 0 };
		//string search = text.find(m_badWords[i]);
		do {
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				count[i]++;
			}
		} while (i++ < MAX_WORDS);
	}
	void SpellChecker::showStatistics(std::ostream& out) const {
		for (size_t i = 0; i < MAX_WORDS; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << count[i] << "replacements" << std::endl;
		}
	}
}