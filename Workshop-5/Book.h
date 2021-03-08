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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <iomanip>
#include <string>
namespace sdds {
	typedef std::string string;
	class Book {
		string b_author{};
		string b_title{};
		string b_country{};
		size_t b_year{ 0 };
		double b_price{ 0 };
		string b_description{};
	public:
		Book() {};
		const std::string& author() const;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		const std::string& description() const;
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& bck);

		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(b_description);
		}
	};
}
#endif