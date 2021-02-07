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
	template <unsigned N, class T>
	class Set {
		T s_collection[N];	//statically allocated array of any datatype
		size_t elemsInCollection{ 0 };	//current number of elements in the collection
	public:
		size_t size() const;	//returns the current number of elements in the collection
		const T& get(size_t idx) const;	//returns a reference to the element at index idx of s_collection
		void operator+=(const T& item);	//if the collection has capacity, adds a copy of item to the collection
	};

	template<unsigned N, class T>
	inline size_t Set<N, T>::size() const {
		return elemsInCollection;
	}
	template<unsigned N, class T>
	inline const T& Set<N, T>::get(size_t idx) const {
		return s_collection[idx];
	}
	template<unsigned N, class T>
	inline void Set<N, T>::operator+=(const T& item) {
		if (this->size() < N) {
			s_collection[size()] = item;
			elemsInCollection++;
		}
	}
}
#endif