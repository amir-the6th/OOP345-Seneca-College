/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-04-13            ///
|*******************************************|
|**********  Final Project - MS3  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/
#include <iostream>
#include <string>
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
		else {
			while (std::getline(f, line)) {
				if (!line.empty()) {
					item = token.extractToken(line, next_pos, more);
					if (more) {
						nextItem = token.extractToken(line, next_pos, more);
					}
					else {
						nextItem = "";
					}
					for (auto st1 : stations) {
						if (item == st1->getItemName()) {
							if (!nextItem.empty()) {
								for (auto st2 : stations) {
									if (st2->getItemName() == nextItem) {
										st1->setNextStation(st2);
									}
								}
							}
							activeLine.push_back(st1);
						}
					}
				}
			}
			f.close();
			m_firstStation = activeLine.front();
			m_cntCustomerOrder = pending.size();
		}
	}
	void LineManager::linkStations() {
		/*this modifier reorders the workstations present in the instance variable activeLine(loaded by the constructor) 
		and stores the reordered collection in the same instance variable.The elements in the reordered collection start 
		with the first station, proceeds to the next, and so forth until the end of the line.*/

		/*Workstation* elem{ m_firstStation };
		std::vector<Workstation*> local;
		while (elem != nullptr) {
			local.push_back(elem);
			elem = (Workstation*)elem->getNextStation();
		}
		activeLine = local;*/

		for (size_t i = activeLine.size(); i > 0; i--) {
			Workstation* elem{ activeLine[i] };
			for (size_t j = 0; j < i; j++) {
				if (elem == activeLine[j]->getNextStation()) {
					std::swap(activeLine[i - 1], activeLine[j]);
				}
			}
		}
	}
	bool LineManager::run(std::ostream& os) {
		static size_t count{ 0 };
		os << "Line Manager Iteration: " << ++count << std::endl;
		if (!pending.empty()) {
			*activeLine.front() += std::move(pending.front());
			pending.pop_front();
		}
		for (auto aL : activeLine)
			aL->fill(os);

		for (auto aL : activeLine)
			aL->attemptToMoveOrder();

		return completed.size() == m_cntCustomerOrder;
	}
	void LineManager::display(std::ostream& os) const {
		for (auto aL : activeLine) {
			aL->display(os);
		}
	}
}