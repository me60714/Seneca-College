// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.15
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds {
    TimedEvents::TimedEvents(){numberOfEvents = 0;}

    // TimedEvents::~TimedEvents()
    // {
    //     ;
    // }

    void TimedEvents::startClock(){start_time = std::chrono::steady_clock::now();}

    void TimedEvents::stopClock(){end_time = std::chrono::steady_clock::now();}

    void TimedEvents::addEvent(const char* name)
    {
        auto timeDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
        
        if(numberOfEvents < MaxEvents)
        {
            this->events[numberOfEvents].m_eventName = name;
            this->events[numberOfEvents].m_units = "nanoseconds";
            this->events[numberOfEvents].m_duration = timeDuration;
            numberOfEvents++;
        }

    }

    std::ostream &operator<<(std::ostream& os, const TimedEvents& events)
    {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        
        for (int i = 0; i < events.numberOfEvents; i++)
        {
            os << std::setw(21) << std::left;
            os << events.events[i].m_eventName;
            os << ' ' << std::setw(13) << std::right;
            os << events.events[i].m_duration.count() << ' ' << events.events[i].m_units << endl;
        }
        
        os << "--------------------------\n";
        return os;
    }
}