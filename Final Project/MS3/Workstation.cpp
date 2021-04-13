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
#include "Workstation.h"

namespace sdds {
	std::deque<CustomerOrder> pending;
	std::deque<CustomerOrder> completed;
	std::deque<CustomerOrder> incomplete;

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
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (m_pNextStation == nullptr) {
					completed.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
					moved = true;
				}
				else {
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					moved = true;
				}
			}
			else if (this->getQuantity() <= 0) {
				if (m_pNextStation == nullptr) {
					incomplete.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
					moved = true;
				}
				else {
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					moved = true;
				}
			}
		}
		return moved;
	}
	void Workstation::setNextStation(Workstation* station) {
		//this modifier stores the address of the referenced Workstation object in the pointer to the m_pNextStation
		m_pNextStation = station;
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
			os << getItemName() << " --> " << "End of line" << std::endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		// moves the CustomerOrder referenced in parameter newOrder to the back of the queue
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}
