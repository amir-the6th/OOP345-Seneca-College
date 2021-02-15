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

#ifndef SDDS_CONFORMATIONSENDER_H
#define SDDS_CONFORMATIONSENDER_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** cs_res;
		size_t cs_count;
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(ConfirmationSender& src); //mandatory member function of class with resource: copy constructor
		ConfirmationSender& operator=(const ConfirmationSender& src); //mandatory member function of class with resource: copy-assignment operator
		ConfirmationSender(ConfirmationSender&& src)noexcept; //mandatory member function of class with resource: move constructor
		ConfirmationSender& operator=(ConfirmationSender&& src)noexcept; //mandatory member function of class with resource: move-assignment operator
		size_t size() const;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& CS);
	};
}
#endif