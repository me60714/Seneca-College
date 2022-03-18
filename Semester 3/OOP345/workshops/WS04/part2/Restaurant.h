// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 07.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include "Reservation.h"

namespace sdds
{
    class Restaurant
    {
        Reservation* m_reservation{};
        size_t m_resNum{};
    public:
        //default constructor
        Restaurant();
        //one argument constructor
        Restaurant(const Reservation* reservations[], size_t cnt);
        //destructor
        ~Restaurant();
        //copy constructor
        Restaurant(const Restaurant& rest);
        //copy assignment
        Restaurant& operator=(const Restaurant& rest);
        //move constructor
        Restaurant(Restaurant&& rest);
        //move assignment
        Restaurant &operator=(Restaurant&& rest);

        size_t size() const;
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& rest);
    };
}