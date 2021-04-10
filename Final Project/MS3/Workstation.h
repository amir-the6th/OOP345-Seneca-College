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
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
	extern std::deque<CustomerOrder> pending; //holds the orders to be placed onto the assembly line at the first station
	extern std::deque<CustomerOrder> completed; //holds the orders that have been removed from the last station and have been completely filled
	extern std::deque<CustomerOrder> incomplete; //holds the orders that have been removed from the last station and could not be filled completely

	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders; //orders that have been placed on this station to receive service (or already received service)
		Workstation* m_pNextStation{ nullptr }; //a pointer to the next Workstation on the assembly line
	public:
		Workstation(std::string str) : Station(str) {};
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

		/*Since a Workstation object represents a single location on the assembly line
		for filling customer orders with items, the object cannot be copied or moved.*/
		Workstation(const Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation(Workstation&&) noexcept = delete;
		Workstation& operator=(Workstation&&) noexcept = delete;
	};
}
#endif