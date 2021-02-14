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

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <iostream>
#include <string>

namespace sdds {
	class Reservation {
		std::string r_resID; //an array of characters
		std::string r_resName; //the name on the reservation
		std::string r_resEmail; //the email to be used to send a confirmation
		int r_noOfPeople; //the number of people in the party
		int r_day; //the day when the party expects to come (1-28)
		int r_hour; //the hour when the party expects to come (1-24)
	public:
		Reservation(); //default constructor
		Reservation(const std::string& res); //extract information about the reservation from the string and store in the instance's attributes
		friend std::ostream& operator<<(std::ostream& os, const Reservation& RES); //insert the contents of a reservation object into an ostream object
	};
}
#endif