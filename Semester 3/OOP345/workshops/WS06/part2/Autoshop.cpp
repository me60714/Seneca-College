// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Autoshop.h"

using namespace std;
namespace sdds
{
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------" << endl;
        out << "| Cars in the autoshop!        |" << endl;
        out << "--------------------------------" << endl;
    
        for (std::vector<Vehicle *>::const_iterator i = m_vehicles.begin(); i != m_vehicles.end(); i++)
        {
            (*i)->display(out);
            out << endl;
        }
        out << "--------------------------------" << endl;
    }

    Autoshop::~Autoshop()
    {
        for (auto i = m_vehicles.begin(); i < m_vehicles.end(); i++)
        {
            delete *i;
        }
    }
}