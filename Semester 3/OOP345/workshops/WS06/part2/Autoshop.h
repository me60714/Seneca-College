// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Vehicle.h"

namespace sdds
{
    class Autoshop
    {
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator+=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        ~Autoshop();

        template <typename T>
        void select(T test, std::list<const Vehicle*>& vehicles)
        {
            for (std::vector<Vehicle*>::iterator i = m_vehicles.begin(); i < m_vehicles.end(); i++)
            {
                if (test(*i))
                {
                    vehicles.push_back(*i);
                }
            }
        }
    };
}