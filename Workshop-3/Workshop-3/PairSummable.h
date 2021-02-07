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

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include "Pair.h"

namespace sdds {
	template<typename V, typename K>  //the type of the value & the type of the key, respectively
	class PairSummable : public Pair<V, K> {
		static V ps_init;
		static size_t ps_minWidth;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = ps_init) : Pair<V, K>(key, value) {
			size_t objSize = key.size();
			if (objSize > ps_minWidth) ps_minWidth = objSize;
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return this->key() == b.key() ? 1 : 0;
		}
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& PS) {
			PairSummable temp(this->key(), this->value() + PS.value());
			*this = temp;
			return *this;
		}
		void display(std::ostream& os) const {
			os << std::left << std::setw(ps_minWidth);
			Pair<V, K>::display(os);
			os << std::right;
		}
	};

	template<typename V, typename K>
	size_t PairSummable<V, K>::ps_minWidth{ 0u };

	template<>
	std::string PairSummable<std::string, std::string>::ps_init = "";

	template<> 
	int PairSummable<int, std::string>::ps_init{ 0 };

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& PS) {
		*this = PairSummable(this->key(), this->value() != "" ? this->value() + ", " + PS.value() : this->value());
		return *this;
	}
}
#endif