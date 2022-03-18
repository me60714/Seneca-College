// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <istream>
#include "Car.h"

namespace sdds
{
    class Racecar : public Car
    {
        double m_booster{0};

    public:
        Racecar(std::istream& in);
        void display(std::ostream& out) const;
        double topSpeed() const;
    };
}