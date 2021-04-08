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
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"

namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine; //the collection of workstations for the current assembly line
		size_t m_cntCustomerOrder{ 0 }; //the total number of CustomerOrder objects
		Workstation* m_firstStation; //points to the first active station on the current line
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif