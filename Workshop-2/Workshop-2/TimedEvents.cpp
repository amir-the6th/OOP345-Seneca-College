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

#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents() {
		e_noCurrentRecords = { 0 };
		e_startTime = {};
		e_endTime = {};
		events->e_eventName = {};
		events->e_unitsOfTime = {};
		events->eventDuration = {};
	}

	void TimedEvents::startClock() {
		e_startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		e_endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName) {
		if (e_noCurrentRecords < MAX_NO_EVENTS) {
			events[e_noCurrentRecords].e_eventName = eventName;
			events[e_noCurrentRecords].e_unitsOfTime = "nanoseconds";
			events[e_noCurrentRecords].eventDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(e_endTime - e_startTime);
			e_noCurrentRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& os, TimedEvents& TE) {
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < TE.e_noCurrentRecords; i++) {
			os << std::setw(20) << std::left << TE.events[i].e_eventName;
			os << std::setw(12) << std::right << TE.events[i].eventDuration.count()
				<< " " << TE.events[i].e_unitsOfTime << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}