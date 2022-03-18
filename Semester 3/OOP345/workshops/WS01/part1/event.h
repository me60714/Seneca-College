// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_

#include <iostream>

using namespace std;

extern unsigned int g_sysClock;

namespace sdds{
    class Event
    {
        char description[128];
        unsigned int time = 0;
    public:
        Event();
        void display() const;
        void set(const char* desc = nullptr);
    };
}

#endif