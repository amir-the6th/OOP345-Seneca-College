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
#include "Utilities.h"

namespace sdds {
    Vehicle* sdds::createInstance(std::istream& in) {
        std::string temp{};
        in >> temp;
        if (temp[0] == 'c' || temp[0] == 'C') {
            return new Car(in);
        }
        else {
            return nullptr;
        }
    }

    //trim utility
    string& trim(string& str) {
        const char* charsToOmit{ " \f\n\r\t\v" };
        string temp{};
        temp = str.substr(0, str.find(","));
        temp.erase(0, temp.find_first_not_of(charsToOmit));
        temp.erase(temp.find_last_not_of(charsToOmit) + 1);
        str.erase(0, str.find(",") + 1);
        return temp;
    }
}
