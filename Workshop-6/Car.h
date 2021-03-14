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

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
	class Car : public Vehicle {
		string c_maker{""}; //maker
		string c_condition{""}; //condition: a car can be new, used, or broken in need of repairs.
		double c_topSp{ 0 }; //top speed
	public:
		Car() {};
		~Car() {};
		Car(std::istream& is);
		string maker() const;
		string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif