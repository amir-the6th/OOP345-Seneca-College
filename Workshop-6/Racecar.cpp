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
		try {
			std::string temp{};
			std::getline(in, temp, ',');
			m_booster = std::stod(trim(temp));
		}
		catch (...) {
			throw std::invalid_argument("Invalid record!");
		}
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const {
		return (Car::topSpeed() + (Car::topSpeed() * m_booster));
	}
}
