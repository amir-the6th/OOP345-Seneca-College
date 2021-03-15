/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-14            ///
|*******************************************|
|*********  Workshop 6 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles; //all the vehicles available at this autoshop
	public:
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle); //adds the vehicle received as parameter into the m_vehicles vector
		void display(std::ostream& out) const;

		template<class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif