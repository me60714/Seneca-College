// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.15
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_

#include <iostream>

using namespace std;

extern unsigned int g_sysClock;

namespace sdds{
    class Event
    {
        char* description = nullptr;
        unsigned int time = 0;
    public:
        Event();
        Event(const Event&);  //copy constructor
        ~Event();
        void display() const;
        void set(const char* desc = nullptr);
        Event& operator=(const Event&); //copy assignment
    };
}

#endif