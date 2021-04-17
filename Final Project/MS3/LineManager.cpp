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
#include <set>
#include "LineManager.h"
#include "Utilities.h"

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		std::ifstream f(file);
		Utilities token;
		std::string line{}, item{}, nextItem{};
		size_t next_pos{ 0 };
		bool more{ false };
		std::set<std::string> col1Records, col2Records, diff;
		
		if (!f) {
			throw std::string("Err: Unable to open the file!");
		}
		else {
			while (std::getline(f, line)) {
				if (!line.empty()) {
					item = token.extractToken(line, next_pos, more);
					col1Records.insert(item);
					nextItem = !more ? "" : token.extractToken(line, next_pos, more), col2Records.insert(nextItem);

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
			//m_firstStation = activeLine.front();
			std::set_difference(col1Records.begin(), col1Records.end(),
				col2Records.begin(), col2Records.end(),
				std::inserter(diff, diff.end()));
			auto it = find_if(stations.begin(), stations.end(), [diff](const Workstation* st)
				{ return st->getItemName() == (*diff.begin()); });
			m_firstStation = *it; 

			m_cntCustomerOrder = pending.size();
		}
	}
	void LineManager::linkStations() {
		Workstation* it = m_firstStation;
		std::vector<Workstation*> local;
		while (it) {
			local.push_back(it);
			it = it->getNextStation();
		}
		activeLine = local;

		//for (size_t i = activeLine.size(); i > 0; i--) {
		//	Workstation* elem{ activeLine[i] };
		//	for (size_t j = 0; j < i; j++) {
		//		if (elem == (Workstation*)activeLine[j]->getNextStation()) {
		//			std::swap(activeLine[i - 1], activeLine[j]);
		//		}
		//	}
		//}
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