///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.13            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef TRUCK_H_
#define TRUCK_H_

#include <iostream>
#include "MotorVehicle.h"

using namespace std;

namespace sdds{
    class Truck : public MotorVehicle{
        float m_maxLoad; //kg, 2precision
        float m_currentLoad; // cannot exceed maxLoad
    public:
        Truck(const char* plateNumber, int builtYear, float maxLoad, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        ostream &write(ostream &os) const;
        istream &read(istream &in);
    };
    ostream &operator<<(ostream &ostr, const Truck &truck);
    istream &operator>>(istream &istr, Truck &truck);
}


#endif