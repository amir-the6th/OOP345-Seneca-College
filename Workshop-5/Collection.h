/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-06            ///
|*******************************************|
|*********  Workshop 5 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
namespace sdds {
	typedef std::string string;
	template <class T>
	class Collection {
		string c_name{};
		T* c_objects{};
		size_t c_size{ 0 };
		void (*c_observer)(const Collection<T>&, const T&) {};
	public:
		Collection(const string& name) : c_name(name) {}
		Collection(Collection&) = delete;
		Collection& operator=(Collection&) = delete;
		Collection(Collection&&) = delete;
		Collection& operator=(Collection&&) = delete;
		~Collection() {
			delete[] c_objects;
		}
		const string& name() const {
			return c_name;
		}
		size_t size() const {
			return c_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool same{ false };
			for (size_t i = 0; i < size() && !same; i++) {
				if (c_objects[i].title() == item.title()) same = true;
			}
			if (!same) {
				T* tempObj = new T[size() + 1]; //open space for a new item
				for (size_t j = 0; j < size(); j++) tempObj[j] = c_objects[j];
				tempObj[c_size++] = item;

				delete[] c_objects;
				c_objects = tempObj;
				delete[] tempObj;
				if (c_observer != nullptr) c_observer(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= size()) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.");
			}
			else {
				return c_objects[idx];
			}
		}
		T* operator[](const string& title) const {
			for (size_t i = 0; i < size(); i++) {
				if (c_objects[i].title() == title) {
					return &c_objects[i];
				}
				else {
					return nullptr;
				}
			}
		}
		friend std::ostream& operator<<(std::ostream& os, const Collection& col) {
			for (size_t i = 0; i < col.size(); i++) os << col[i];
			return os;
		}
	};
}
#endif