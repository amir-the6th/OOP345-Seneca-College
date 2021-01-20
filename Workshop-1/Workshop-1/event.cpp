/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-01-19            ///
|*******************************************|
|*********  Workshop 1 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned int g_sysClock = 0;
char empty[] = { '\0' };

namespace sdds {
	Event::Event() : e_desc(nullptr), e_startTime(0) {
	}
	Event::Event(const Event& cpEvent) {
		e_desc = nullptr;
		*this = cpEvent;
	}
	Event::~Event() {
		delete[] e_desc;
		e_desc = nullptr;
	}
	Event& Event::operator=(const Event& cpEvent) {
		if (cpEvent.e_desc != nullptr) {
			e_startTime = cpEvent.e_startTime;
			delete[] e_desc;
			e_desc = nullptr;
			e_desc = new char[strlen(cpEvent.e_desc) + 1];
			strcpy(e_desc, cpEvent.e_desc);
		}
		else {
			e_startTime = 0;
			delete[] e_desc;
			e_desc = nullptr;
		}
		return *this;
	}
	void Event::display(){
		static int counter = 1;
		int hour = e_startTime / 3600, 
			min = ((e_startTime % 3600) / 60),
			sec = ((e_startTime % 3600) % 60);
		if (e_desc[0] != '\0') {
			std::cout << counter << ". " 
				<< std::setw(2) << std::setfill('0') << hour << ':' 
				<< std::setw(2) << std::setfill('0') << min << ':'
				<< std::setw(2) << std::setfill('0') << sec << " => "
				<< e_desc << std::endl;
		}
		else {
			std::cout << counter << ". | No Event |" << std::endl;
		}
		counter++;
	}
	void Event::set(char* newEvent) {
		if (newEvent != nullptr) {
			e_startTime = g_sysClock;
			delete[] e_desc;
			e_desc = nullptr;
			e_desc = new char[strlen(newEvent) + 1];
			strcpy(e_desc, newEvent);
		}
		else {
			e_startTime = 0;
			delete[] e_desc;
			e_desc = nullptr;
		}
	}
}
