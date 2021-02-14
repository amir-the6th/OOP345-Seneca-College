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

#include <iostream>
#include <iomanip>
#include "Reservation.h"
using namespace std;

namespace sdds {
	Reservation::Reservation() : r_resID{ nullptr }, r_resName{ nullptr }, r_resEmail{ nullptr }, r_noOfPeople{ 0 }, r_day{ 1 }, r_hour{ 1 }{
	}
	Reservation::Reservation(const std::string& res) {
		std::string str = res; //temp reservation string
		std::string id, name, email, numPeople, day, hour; //temp variables to hold data

		//ID
		id = str.substr(0, str.find(':')); //constructs a string that starts from pos 0 to ':' and assigns the substring to the variable
		str.erase(0, str.find(':') + 1); //erase the part of the string from pos 0 to ':'

		//Name
		name = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//Email
		email = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//Party Size
		numPeople = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//Day
		day = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//Hour
		hour = str.substr(0, str.find(','));
		str.erase(0, str.find(',') + 1);

		//trim whitespace
		id.erase(0, id.find_first_not_of(' '));
		id.erase(id.find_last_not_of(' ') + 1);
		name.erase(0, name.find_first_not_of(' '));
		name.erase(name.find_last_not_of(' ') + 1);
		email.erase(0, email.find_first_not_of(' '));
		email.erase(email.find_last_not_of(' ') + 1);

		//store the tokens in the instance's attributes
		r_resID = id;
		r_resName = name;
		r_resEmail = email;
		r_noOfPeople = stoi(numPeople); //parses str and interprets it as an int
		r_day = stoi(day);
		r_hour = stoi(hour);
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& RES) {
		os << "Reservation " << right << setw(10) << RES.r_resID << ": " << setw(20) << RES.r_resName << "  " << left << setw(20) << '<' << RES.r_resEmail << '>' << "    ";
		if (RES.r_hour >= 6 && RES.r_hour <= 9) {
			os << "Breakfast";
		}
		else if (RES.r_hour >= 11 && RES.r_hour <= 15) {
			os << "Lunch";
		}
		else if (RES.r_hour >= 17 && RES.r_hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}
		os << " on day " << RES.r_day << " @ " << RES.r_hour << ":00 for " << RES.r_noOfPeople << (RES.r_noOfPeople == 1 ? " person." : " people.") << endl;

		return os;
	}
}
