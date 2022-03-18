// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 05.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds
{
    Reservation::Reservation(){};

    void Reservation::update(int day, int time)
    {
        m_day = day;
        m_hour = time;
    }

    Reservation::Reservation(const string& str)
    {
        string id, name, email;
        int people, day, hour;
        string temp = str;

        size_t comma = str.find(",");
        for (size_t i = str.length() - 1; i > comma; --i)
        {
            if (str[i] == ' ')
            {
                temp.erase(i, 1);
            }
        }

        //locate ID
        id = temp.substr(0, temp.find(":"));
        //erase ID space
        id.erase(0, id.find_first_not_of(" "));
        id.erase(id.find_last_not_of(" ") + 1);
        //erase temp space
        temp.erase(0, temp.find(":") + 1);

        //locate Name
        name = temp.substr(0, temp.find(","));
        //erase Name space
        name.erase(0, name.find_first_not_of(" "));
        name.erase(name.find_last_not_of(" ") + 1);
        //erase temp space
        temp.erase(0, temp.find(",") + 1);

        //locate email
        email = temp.substr(0, temp.find(","));
        //erase temp space
        temp.erase(0, temp.find(",") + 1);

        //locate people
        people = stoi(temp.substr(0, temp.find(",")));
        //erase temp space
        temp.erase(0, temp.find(",") + 1);

        //locate day
        day = stoi(temp.substr(0, temp.find(",")));
        //erase temp space
        temp.erase(0, temp.find(",") + 1);

        //locate time
        hour = stoi(temp.substr(0, temp.find(" ")));

        m_id = id;
        m_name = name;
        m_email = email;
        m_numOfPpl = people;
        m_day = day;
        m_hour = hour;
    }

    ostream &operator<<(ostream& os, const Reservation& res)
    {
        string aloneOrNot = " people.";
        if(res.m_numOfPpl == 1){aloneOrNot = " person.";}

        os << "Reservation ";
        os.width(10);
        os.setf(ios::right);
        os << res.m_id << ": ";
        os.width(20);
        os << res.m_name << "  ";
        os.unsetf(ios::right);
        os.setf(ios::left);
        os.width(20);
        os << "<" + res.m_email + ">" << "    ";

        if (res.m_hour >= 6 && res.m_hour <= 9)
        {
            os << "Breakfast on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPpl << aloneOrNot << endl;
        }
        else if (res.m_hour >= 11 && res.m_hour <= 15)
        {
            os << "Lunch on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPpl << aloneOrNot << endl;
        }
        else if (res.m_hour >= 17 && res.m_hour <= 21)
        {
            os << "Dinner on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPpl << aloneOrNot << endl;
        }
        else
        {
            os << "Drinks on day " << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPpl << aloneOrNot << endl;
        }
        return os;
    }

}