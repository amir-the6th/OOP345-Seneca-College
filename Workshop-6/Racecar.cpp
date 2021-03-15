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
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		in >> m_booster;
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const {
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}
