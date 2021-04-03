/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-03-27            ///
|*******************************************|
|**********  Final Project - MS1  **********|
|*******************************************|
|    I confirm that I have done all the     |
|    coding by myself and that I am the     |
//       only author of this file.	        |
********************************************/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <iomanip>
#include <string>

namespace sdds {
	typedef std::string string;
	class Station {
		size_t s_id{}; //the id of the station
		string s_name{}; //the name of the item handled by the station
		string s_description{}; //the description of the station
		size_t s_nextSerialNo{ 0 }; //the next serial number to be assigned to an item at this station
		size_t s_numInStock{ 0 }; //the number of items currently in stock
		static size_t m_widthField; // the maximum number of characters required to print to the screen
		static size_t id_generator; //a variable used to generate IDs for new instances of type Station
	public:
		Station(const string& str);
		const string& getItemName() const; //returns the name of the current Station object
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif