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
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		std::ifstream f(file);
		Utilities token;
		std::string line{}, item{}, nextItem{};
		size_t next_pos{ 0 };
		bool more{ false };
		
		if (!f) {
			throw std::string("Err: Unable to open the file!");
		}
		while (std::getline(f, line)) {
			item = token.extractToken(line, next_pos, more);
			for (auto i : stations) {
				if
			}
		}
	}
	void LineManager::linkStations() {
	}
	bool LineManager::run(std::ostream& os) {
		static size_t count{ 0 };
		os << "Line Manager Iteration: " << ++count << std::endl;
		return false;
	}
	void LineManager::display(std::ostream& os) const {
	}
}