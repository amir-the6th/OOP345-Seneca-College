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
#include "Autoshop.h"
namespace sdds {
    Autoshop::~Autoshop() {
        for (auto vehicle : m_vehicles) {
            delete vehicle;
        }
    }
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out) const {
        out << "--------------------------------\n"
            << "| Cars in the autoshop!        |\n"
            << "--------------------------------\n";
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i)->display(out); 
            out << std::endl;
        }
        out << "--------------------------------\n";
    }
}
