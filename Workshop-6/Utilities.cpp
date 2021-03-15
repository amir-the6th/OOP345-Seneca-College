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
#include <sstream>
#include "Utilities.h"
#include "Racecar.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in) {
        std::string temp{}, type{};
        std::getline(in, temp, '\n');
        type = trim(temp);

        std::stringstream str;
        if (!temp.empty()) {
            if (type == "c" || type == "C") {
                str << temp;
                return new Car(str);
            }
            else if (type == "r" || type == "R") {
                str << temp;
                return new Racecar(str);
            }
            else {
                throw type[0];
            }
        }
        else return nullptr;
    }

    //trim utility
    std::string trim(std::string& str) {
        const char* charsToOmit{ " \f\n\r\t\v" };
        std::string temp{};
        temp = str.substr(0, str.find(","));
        temp.erase(0, temp.find_first_not_of(charsToOmit));
        temp.erase(temp.find_last_not_of(charsToOmit) + 1);
        str.erase(0, str.find(",") + 1);
        return temp;
    }
}
