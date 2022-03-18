// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include "Racecar.h"

using namespace std;
namespace sdds
{
    Racecar::Racecar(std::istream& in) : Car(in)
    {
        string temp;
        getline(in, temp, '\n');
        m_booster = std::stod(temp);
    }

    void Racecar::display(std::ostream& out) const
    {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const
    {
        return (Car::topSpeed() + (Car::topSpeed() * m_booster));
    }
}