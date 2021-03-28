/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-27            ///
|*******************************************|
|**********  Final Project - MS1  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/
#include "Station.h"

namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const string& str) {
    }
    const string& Station::getItemName() const {
        return s_name;
    }
    size_t Station::getNextSerialNumber() {
        return s_nextSerialNo++;
    }
    size_t Station::getQuantity() const {
        return s_inStock;
    }
    void Station::updateQuantity() {
        s_inStock = s_inStock < 0 ? 0 : s_inStock - 1;
    }
    void Station::display(std::ostream& os, bool full) const {
        os << '[' << std::setw(3) << std::setfill('0') << std::right << s_id
            << "] Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << s_name
            << " [" << std::setw(6) << std::setfill('0') << std::right << s_nextSerialNo << "]" 
            << std::setfill(' ') << std::left;
        if (full) {
            os << " Quantity: " << std::setw(m_widthField) << s_inStock
                << " Description: " << s_description;
        }
        os << std::endl;
    }
}
