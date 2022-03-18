// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"

using namespace std;
unsigned int g_sysClock = 0;

namespace sdds {
    Event::Event()
    {
        ;
    }

    void Event::display() const {

        static unsigned int counter = 0;

        ios init(NULL);
        init.copyfmt(cout);

        cout.width(2);
        cout << ++counter << ". ";

        if (this->description[0] != '\0')
        {
            unsigned int HH = 0;
            unsigned int MM = 0;
            unsigned int SS = 0;
            HH = this->time / (60 * 60);
            MM = (this->time % 3600) / 60;
            SS = (this->time % 60);

            cout.fill('0');
            cout.width(2);
            cout << HH << ":";
            cout.fill('0');
            cout.width(2);
            cout << MM << ":";
            cout.fill('0');
            cout.width(2);
            cout << SS << " => " << description << endl;

            cout.copyfmt(init);
        }
        else
        {
            cout << "| No Event |" << endl;
        }
    }

    void Event::set(const char *desc)
    {
        // this->time = ::g_sysClock;

        if (desc)
        {
            strncpy(this->description, desc, 128);
        }
        else
        {
            this->description[0] = '\0';
        }
    }
}