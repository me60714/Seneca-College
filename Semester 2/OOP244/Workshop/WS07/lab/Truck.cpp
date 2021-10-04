///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.13            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Truck.h"

using namespace std;
namespace sdds{
    Truck::Truck(const char* plateNumber, int builtYear, float maxLoad, const char *address) : MotorVehicle(plateNumber, builtYear)
    {
        m_maxLoad = maxLoad;
        m_currentLoad = 0.0;
        moveTo(address);
    }

    bool Truck::addCargo(double cargo)
    {
        bool added = false;
        if (cargo + m_currentLoad <= m_maxLoad)
        {
            m_currentLoad += cargo;
            added = true;
        }
        else if (m_currentLoad != m_maxLoad)
        {
            m_currentLoad = m_maxLoad;
            added = true;
        }
        return added;
    }

    bool Truck::unloadCargo()
    {
        bool changed = false;
        if (m_currentLoad != 0)
        {
            m_currentLoad = 0;
            changed = true;
        }
        return changed;
    }

    ostream& Truck::write(ostream &os) const
    {
        MotorVehicle::write(os) << " | " << m_currentLoad << "/" << m_maxLoad;
        return os;
    }

    istream& Truck::read(istream &in)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_maxLoad;
        cout << "Cargo: ";
        in >> m_currentLoad;
        return in;
    }

    ostream &operator<<(ostream &ostr, const Truck &truck) {return truck.write(ostr);}
    istream &operator>>(istream &istr, Truck &truck) {return truck.read(istr);}

}