// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
// try to use pragma once here

#include <iostream>
#include <chrono>

namespace sdds{
    const int MaxEvents = 10;
    class TimedEvents
    {
        int numberOfEvents = 0;
        std::chrono::steady_clock::time_point start_time;
        std::chrono::steady_clock::time_point end_time;
        
        struct Event
        {
            std::string m_eventName;
            std::string m_units;
            std::chrono::steady_clock::duration m_duration;
        } events[MaxEvents];

    public:
        TimedEvents();
        void startClock();
        void stopClock();
        void addEvent(const char* name);
        friend std::ostream &operator<<(std::ostream& os, const TimedEvents& events);
    };
}