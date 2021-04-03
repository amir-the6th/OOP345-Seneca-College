/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-04-03            ///
|*******************************************|
|**********  Final Project - MS2  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {
    size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities token;
        size_t next_pos{ 0 };
        bool more{ false };

        if (!str.empty()) {
            m_name = token.extractToken(str, next_pos, more);
            if (more) {
                m_product = token.extractToken(str, next_pos, more);
            }
            if (more) {
                while (more) {
                }
            }
        }
	}
}
