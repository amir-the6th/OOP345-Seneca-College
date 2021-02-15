/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-02-14            ///
|*******************************************|
|*********  Workshop 4 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#include <algorithm>    // std::swap
#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant() : rs_restaurant{ nullptr }, rs_count{ 0 } {
	}
	Restaurant::~Restaurant() {
		delete[] rs_restaurant;
		rs_restaurant = nullptr;
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		rs_restaurant = new Reservation[cnt];
		for (size_t i = 0; i < cnt; i++) {
			rs_restaurant[i] = *reservations[i];
		}
		rs_count = cnt;
	}
	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (src.rs_restaurant != nullptr) {
			rs_restaurant = new Reservation[src.size() + 1];
			for (size_t i = 0; i < src.rs_count; i++) {
				rs_restaurant[i] = src.rs_restaurant[i];
			}
			rs_count = src.rs_count;
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& src)noexcept {
		*this = std::move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)noexcept {
		if (src.rs_restaurant != nullptr) {
			std::swap(rs_restaurant, src.rs_restaurant);
			rs_count = src.rs_count;
			src.rs_count = 0;
			src.rs_restaurant = nullptr;
		}
		return *this;
	}
	size_t Restaurant::size() const {
		return rs_count;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& RES) {
		static size_t cnt{ 1 };

		os << "--------------------------\n";
		os << "Fancy Restaurant (" << cnt++ << ")\n";
		os << "--------------------------\n";
		if (RES.rs_count == 0) {
			os << "--------------------------\n";
			os << "This restaurant is empty!\n";
			os << "--------------------------\n";
		}
		else {
			for (size_t i = 0; i < RES.rs_count; i++) {
				os << RES.rs_restaurant[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}
}
