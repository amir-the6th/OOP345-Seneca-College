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

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;
extern char empty[];

namespace sdds {
	class Event {
		char* e_desc; //the description of the event
		unsigned int e_startTime; //the time when the event starts (seconds) - between 0 to 86400
		void setEmpty(); //reset to empty state
	public:
		Event();
		Event(const Event& cpEvent);
		~Event();
		Event& operator=(const Event& cpEvent);
		void display();
		void set(char* = empty); // default argument is considered for it.
							     // this way, we can call set() (ex. case 'E' line 95 in w1_p1.cpp)
	};
}
#endif // !SDDS_EVENT_H
