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
	/*string& trim(string& str) {
		string charsToOmit{ " \f\n\r\t\v" }, temp{};
		temp = str.substr(0, str.find(","));
		temp.erase(0, temp.find_first_not_of(charsToOmit));
		temp.erase(temp.find_last_not_of(charsToOmit) + 1);
		str.erase(0, str.find(",") + 1);
		return temp;
	}*/

	Car::Car(std::istream& is) {
		std::string temp;

		//Maker
		std::getline(is, temp, ',');
		c_maker = trim(temp);

		//Condition
		std::getline(is, temp, ',');
		temp = trim(temp);
		if (temp.empty())
			c_condition = 'n';
		else {
			c_condition = temp[0];

			if (c_condition != 'n' && c_condition != 'u' && c_condition != 'b')
				throw std::invalid_argument("the record is invalid");
		}

		//Top Speed
		try {
			std::getline(is, temp, ',');
			c_topSp = stod(trim(temp));
		}
		catch (std::invalid_argument& invalid) {
			throw invalid;
		}
	}
	string Car::maker() const {
		return c_maker;
	}
	string Car::condition() const {
		std::string cond;
		if (c_condition == 'n') {
			cond = "new";
		}
		else if (c_condition == 'u') {
			cond = "used";
		}
		else if (c_condition == 'b') {
			cond = "broken";
		}
		return cond;
	}
	double Car::topSpeed() const {
		return c_topSp;
	}
	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << std::right << maker() 
			<< " | " << std::setw(6) << std::left << condition() 
			<< " | " << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
}
