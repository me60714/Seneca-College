///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.13            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;
namespace sdds
{
    MotorVehicle::MotorVehicle(const char plateNumber[9], int builtYear)
    {
        if (plateNumber != nullptr && builtYear != 0)
        {
            // m_plateNumber = new char[PLATENUMBER];
            strCpy(m_plateNumber, plateNumber);
            m_builtYear = builtYear;

            // m_address = new char[8];
            strCpy(m_address, "Factory");
        }
        else
            cout << "INVALID DATA" << endl;
    }

    MotorVehicle::~MotorVehicle()
    {
        // delete [] m_plateNumber;
        m_plateNumber[0] = '\0';
        // delete [] m_address;
        m_address[0] = '\0';
        m_builtYear = 0; 
    }

    void MotorVehicle::moveTo(const char address[64])
    {
        if (m_address != address && m_address[0] != '\0')
        {
            cout << "|";
            cout.width(8);
            cout.setf(ios::right);
            cout << m_plateNumber << "| |";
            cout.width(20);
            cout.setf(ios::right);
            cout << m_address << " ---> ";

            // delete[] m_address;
            // m_address = new char[ADDRESSNUMBER];
            m_address[0] = '\0';
            strCpy(m_address, address);

            cout.width(20);
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout << m_address << "|" << endl;
        }
    }

    ostream &MotorVehicle::write(ostream &os) const
    {
        os << "| " << m_builtYear << " | " << m_plateNumber << " | " << m_address;
        return os;
    }

    istream &MotorVehicle::read(istream &in)
    {
        char tempPlateNumber[9];
        char tempAddress[64];
        cout << "Built year: ";
        in >> m_builtYear;
        cout << "License plate: ";
        in >> tempPlateNumber;
        cout << "Current location: ";
        in >> tempAddress;
        
        // delete [] m_plateNumber;
        // m_plateNumber = new char[PLATENUMBER];
        m_plateNumber[0] = '\0';
        strCpy(m_plateNumber, tempPlateNumber);
        
        // delete [] m_address;
        // m_address = new char[ADDRESSNUMBER];
        m_address[0] = '\0';
        strCpy(m_address, tempAddress);

        return in;
    }
    ostream &operator<<(ostream &ostr, const MotorVehicle &vehicle)
    {
        vehicle.write(ostr);
        return ostr;
    }
    istream &operator>>(istream &istr, MotorVehicle &vehicle) { return vehicle.read(istr); }
}