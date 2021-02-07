/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-02-07            ///
|*******************************************|
|*********  Workshop 3 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"

namespace sdds {
	template <unsigned N, class T> //the capacity of the collection and type of the elements in the array, respectively
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T obj(filter);
			for (size_t i = 0u; i < this->size(); i++) {
				if (obj.isCompatibleWith(this->get(i))) {
					obj += this->get(i);
				}
			}
			return obj;
		}
	};
}
#endif