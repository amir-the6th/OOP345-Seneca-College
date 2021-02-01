/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2021-01-31            ///
|*******************************************|
|*********  Workshop 2 - part 1&2  *********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <chrono>
#include <string>
constexpr auto MAX_NO_EVENTS = 10;

namespace sdds {
	class TimedEvents {
		int e_noCurrentRecords;	//the number of records currently stored
		std::chrono::steady_clock::time_point e_startTime;	//the start time for the current event
		std::chrono::steady_clock::time_point e_endTime;	//the end time for the current event
		struct {
			std::string e_eventName;	//a string with the event name
			std::string e_unitsOfTime;	//a string with the predefined units of time
			std::chrono::steady_clock::duration eventDuration;	//the duration of the event
		} events[MAX_NO_EVENTS];
	public:
		TimedEvents();	//default constructor
		void startClock();	//starts the timer for an event
		void stopClock();	//stops the timer for an event
		void addEvent(const char*);	//update the next time-record in the array
		friend std::ostream& operator<<(std::ostream&, TimedEvents&);	//display the records of the array in a specific format
	};
}
#endif