// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
    std::string trim(std::string& str);
    Vehicle* createInstance(std::istream& in);
}