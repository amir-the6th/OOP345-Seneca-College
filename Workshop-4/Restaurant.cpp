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

#include<iostream>
#include <algorithm>    // std::swap
#include "Restaurant.h"

namespace sdds {
	Restaurant::~Restaurant() {
		delete[] rs_res;
		rs_res = nullptr;
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		if (reservations != nullptr) {
			rs_count = cnt;
			this->rs_res = new Reservation[rs_count];
			for (size_t i = 0; i < rs_count; i++) {
				this->rs_res[i] = *reservations[i];
			}
		}
	}
	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			rs_res = new Reservation[src.size() + 1];
			for (size_t i = 0; i < src.rs_count; i++) {
				rs_res[i] = src.rs_res[i];
			}
			rs_count = src.rs_count;
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& src)noexcept {
		*this = std::move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)noexcept {
		if (this != &src) {
			std::swap(rs_res, src.rs_res);
			rs_count = src.rs_count;
			src.rs_count = 0;
			src.rs_res = nullptr;
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
			//os << "--------------------------\n";
			os << "This restaurant is empty!\n";
			os << "--------------------------\n";
		}
		else {
			for (size_t i = 0; i < RES.rs_count; i++) {
				os << RES.rs_res[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}
}
