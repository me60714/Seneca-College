// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 13.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Movie.h"

using namespace std;

namespace sdds
{
    Movie::Movie(){}

    const string& Movie::title() const {return m_title;}

    Movie::Movie(const string& strMovie)
    {
        string temp, title, desc;
        int year;
        temp = strMovie;

        //find title
        title = temp.substr(0, temp.find(","));
        temp.erase(0, temp.find(",") + 1);
        title.erase(0, title.find_first_not_of(" "));
        title.erase(title.find_last_not_of(" ") + 1);

        //find release year
        year = stoi(temp.substr(0, temp.find(",")));
        temp.erase(0, temp.find(",") + 1);

        //find description
        desc = temp;
        desc.erase(0, desc.find_first_not_of(" "));
        desc.erase(desc.find_last_not_of(" ") + 1);

        m_title = title;
        m_year = year;
        m_desc = desc;
    }

    ostream& operator<<(ostream& os, const Movie& movie)
    {
        os.width(40);
        os << movie.title() << " | ";
        os.width(4);
        os << movie.m_year << " | " << movie.m_desc << endl;
        return os;
    }

}