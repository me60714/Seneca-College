// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include "Vehicle.h"

namespace sdds
{
    class Car : public Vehicle
    {
        std::string m_maker{};
        std::string m_condition{};
        double m_topSpeed{0};

    public:
        Car(){};
        ~Car(){};
        Car(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
}