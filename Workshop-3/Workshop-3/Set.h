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

#ifndef SDDS_SET_H
#define SDDS_SET_H
namespace sdds {
	template <unsigned N, class T> //the capacity of the collection and type of the elements in the array, respectively
	class Set {
		T s_collection[N];	//statically allocated array of any datatype
		size_t elemsInCollection{ 0 };	//current number of elements in the collection
	public:
		size_t size() const {
			return elemsInCollection;
		}	//returns the current number of elements in the collection
		const T& get(size_t idx) const {
			return s_collection[idx];
		}	//returns a reference to the element at index idx of s_collection
		void operator+=(const T& item) {
			if (this->size() < N) {
				s_collection[size()] = item;
				elemsInCollection++;
			}
		}	//if the collection has capacity, adds a copy of item to the collection
	};
}
#endif