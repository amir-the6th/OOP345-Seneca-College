/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-04-10            ///
|*******************************************|
|**********  Final Project - MS3  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"

namespace sdds {
	class CustomerOrder {
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		std::string m_name{}; //the name of the customer (e.g., John, Sara, etc)
		std::string m_product{}; //the name of the product being assembled(e.g., Desktop, Laptop, etc)
		size_t m_cntItem{ 0 }; //a count of the number of items in the customer's order
		Item** m_lstItem{ nullptr }; //a dynamically allocated array of pointers. Each element of the array points to a dynamically allocated object of type Item
		static size_t m_widthField; //the maximum width of a field, used for display purposes
	public:
		CustomerOrder() {};
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif