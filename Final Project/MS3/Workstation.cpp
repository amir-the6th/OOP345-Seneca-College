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
#include "Workstation.h"

namespace sdds {
	void Workstation::fill(std::ostream& os) {
		// this modifier fills the order at the front of the queue, 
		// if there are CustomerOrders in the queue; otherwise, does nothing.
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder() {
		//attempts to move the order at the front of the queue to the next station in the assembly line:
		bool moved{ false };

		
		return moved;
	}
	void Workstation::setNextStation(Workstation* station) {
		//this modifier stores the address of the referenced Workstation object in the pointer to the m_pNextStation
		m_pNextStation = station;
		//m_pNextStation = (Workstation *)&station;
	}
	Workstation* Workstation::getNextStation() const {
		// returns the address of next Workstation
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation) {
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else {
			os << getItemName() << " --> " << "END OF LINE" << std::endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		// moves the CustomerOrder referenced in parameter newOrder to the back of the queue
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}
