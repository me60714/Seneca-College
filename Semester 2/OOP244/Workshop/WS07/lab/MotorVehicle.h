///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.13            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef MOTORVEHICLE_H_
#define MOTORVEHICLE_H_

#include <iostream>
using namespace std;

namespace sdds {
    class MotorVehicle {
        char m_plateNumber[9];
        char m_address[64];
        int m_builtYear;
    public:
        MotorVehicle(const char* plateNumber, int builtYear);
        ~MotorVehicle();
        void moveTo(const char *address);
        ostream &write(ostream &os) const;
        istream &read(istream &in);
    };
    ostream &operator<<(ostream &ostr, const MotorVehicle &vehicle);
    istream &operator>>(istream &istr, MotorVehicle &vehicle);
}

#endif