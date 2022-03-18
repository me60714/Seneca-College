// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.15
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
        if(description != nullptr)
            description = nullptr;
    }

    Event::Event(const Event &eve) //copy constructor
    {
        time = eve.time;
        if (eve.description != nullptr)
        {
            description = new char[strlen(eve.description) + 1];
            strcpy(description, eve.description);
        }
        else
            description = nullptr;

    }

    Event::~Event()
    {
        delete[] description;
        description = nullptr;
    }

    void Event::display() const {

        static unsigned int counter = 0;

        ios init(NULL);
        init.copyfmt(cout);

        cout.width(2);
        cout << ++counter << ". ";

        if (description[0] != '\0')
        {
            unsigned int HH = 0;
            unsigned int MM = 0;
            unsigned int SS = 0;
            HH = time / (60 * 60);
            MM = (time % 3600) / 60;
            SS = (time % 60);

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
        // time = ::g_sysClock;

        if (desc)
        {
            description = new char[strlen(desc) + 1];
            strncpy(description, desc, strlen(desc) + 1);
        }
        else
        {
            description[0] = '\0';
        }
    }

    Event &Event::operator=(const Event &eve) //copy assignment
    {
        if (this != &eve)
        {
            time = eve.time;
            delete[] description;
            if (eve.description != nullptr)
            {
                description = new char[strlen(eve.description) + 1];
                strcpy(description, eve.description);
            }
        }
        else
            description = nullptr;

        return *this;
    }
}