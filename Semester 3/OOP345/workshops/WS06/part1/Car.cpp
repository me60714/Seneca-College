// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 02.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <iomanip>
#include "Car.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{

    Car::Car(std::istream& is)
    {
        std::string str;
        std::getline(is, str, ',');
        m_maker = trim(str);

        std::getline(is, str, ',');
        str = trim(str);

        if (str.empty() || m_condition == " " || str[0] == 'n')
            m_condition = "new";
        else
        {
            m_condition = str[0];
            if (m_condition == "u")
            {
                m_condition = "used";
            }
            else if (m_condition == "b")
            {
                m_condition = "broken";
            }
        }

        try
        {
            std::getline(is, str, ',');
            m_topSpeed = stod(trim(str));
        }
        catch (std::invalid_argument &e)
        {
            throw e;
        }
    }

    std::string Car::condition() const
    {
        return m_condition;
    }

    double Car::topSpeed() const
    {
        return m_topSpeed;
    }

    void Car::display(std::ostream& out) const
    {
        out << "| ";
        out.setf(ios::right);
        out.width(10);
        out << m_maker << " | ";
        out.unsetf(ios::right);
        out.setf(ios::left);
        out.width(6);
        out << condition() << " | ";
        out.width(6);
        out.setf(ios::fixed);
        out.precision(2);
        out << topSpeed() << " |";
    }

}