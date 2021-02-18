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
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::~ConfirmationSender() {
		delete[] cs_res;
		cs_res = nullptr;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender& src) {
		*this = src;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (src.cs_res != nullptr) {
			delete[] cs_res;
			cs_res = new const Reservation * [src.cs_count + 1];
			for (size_t i = 0; i < src.cs_count; i++)
			{
				cs_res[i] = src.cs_res[i];
			}
			cs_count = src.cs_count;
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept {
		*this = std::move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept {
		if (src.cs_res != nullptr) {
			std::swap(cs_res, src.cs_res);
			cs_count = src.cs_count;
			src.cs_count = 0;
			src.cs_res = nullptr;
		}
		return *this;
	}
	size_t ConfirmationSender::size() const {
		return cs_count;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool exists{ false };
		for (size_t i = 0; i < cs_count && !exists; i++) {
			if (&res == cs_res[i]) {
				exists = true;
			}
		}
		if (!exists) {
			//resize the array to make room 
			const Reservation** temp = nullptr;
			temp = new const Reservation * [cs_count + 1];
			for (size_t i = 0; i < cs_count; i++) {
				temp[i] = cs_res[i];
			}
			//stores the address of res in the array
			temp[cs_count] = &res;

			cs_count++;
			delete[] cs_res;
			cs_res = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < cs_count; i++) {
			if (cs_res[i] == &res) cs_res[i] = nullptr;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& CS) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (CS.cs_count == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < CS.cs_count; i++) {
				if (CS.cs_res[i] != nullptr) {
					os << *CS.cs_res[i];
				}
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}