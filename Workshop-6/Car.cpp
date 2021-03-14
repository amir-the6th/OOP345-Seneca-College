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
#include "Car.h"

namespace sdds {	
	Car::Car(std::istream& is) {
		string temp{};
		is >> temp;
		
		//Maker
		temp.substr(0, temp.find(','));
		c_maker = trim(temp);
		temp.erase(0, temp.find(',') + 1);

		//Condition
		temp.substr(0, temp.find(','));
		temp = trim(temp);
		switch (temp[0]) {
		case 'n':
			c_condition = "new";
			break;
		case 'b':
			c_condition = "broken";
			break;
		case 'u':
			c_condition = "used";
			break;
		default:
			throw std::invalid_argument("Invalid Condition!");
			break;
		}
		temp.erase(0, temp.find(',') + 1);

		//Top Speed
		temp.substr(0, temp.find(','));
		c_topSp = stod(trim(temp));
		temp.erase(0, temp.find(',') + 1);
	}
	string Car::maker() const {
		return c_maker;
	}
	string Car::condition() const {
		return c_condition;
	}
	double Car::topSpeed() const {
		return c_topSp;
	}
	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << maker() 
			<< " | " << std::setw(6) << std::right << condition() 
			<< " | " << std::fixed << std::setprecision(2) << topSpeed() <<c_topSp << " |";
	}
}
