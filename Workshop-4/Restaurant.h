/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-02-14            ///
|*******************************************|
|*********  Workshop 4 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* rs_res{};
		size_t rs_count{};
	public:
		Restaurant() {}; //default constructor
		~Restaurant(); //mandatory member function of class with resource: destructor
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src); //mandatory member function of class with resource: copy constructor
		Restaurant& operator=(const Restaurant& src); //mandatory member function of class with resource: copy-assignment operator
		Restaurant(Restaurant&& src)noexcept; //mandatory member function of class with resource: move constructor
		Restaurant& operator=(Restaurant&& src)noexcept; //mandatory member function of class with resource: move-assignment operator
		size_t size() const; //returns the number of reservations in the system
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& RES);
	};
}
#endif