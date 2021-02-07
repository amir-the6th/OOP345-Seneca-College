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

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
namespace sdds {
	template<typename V, typename K> //the type of the value & the type of the key, respectively
	class Pair {
		V p_value;	//value component of the pair
		K p_key;	//key component of the pair
	public:
		Pair() : p_value{}, p_key{} {}	//default constructor
		Pair(const K& key, const V& value) 
			: p_value(value), p_key(key) {}	//copies the values referred to by the parameters into the instance variables
		const V& value() const {
			return p_value;
		}	//returns the value component of the pair
		const K& key() const {
			return p_key;
		}	//returns the key component of the pair
		virtual void display(std::ostream& os) const {
			os << p_key << " : " << p_value << std::endl;
		}	//inserts into stream os the key and the value of the pair
	};
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}	//calls the member function display() on pair to insert a pair into stream os
}
#endif