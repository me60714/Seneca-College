// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 13.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Book.h"

using namespace std;

namespace sdds
{
    Book::Book(){}

    const string& Book::title() const {return m_title;}

    const string& Book::country() const {return m_country;}

    const size_t& Book::year() const {return m_year;}

    double& Book::price() {return m_price;}

    Book::Book(const std::string& strBook)
    {
        string temp, author, title, country, desc;
        size_t year;
        double price;
        temp = strBook;

        //find author
        author = temp.substr(0, temp.find(","));
        temp.erase(0, temp.find(",") + 1);
        author.erase(0, author.find_first_not_of(" "));
        author.erase(author.find_last_not_of(" ") + 1);

        //find tite
        title = temp.substr(0, temp.find(","));
        temp.erase(0, temp.find(",") + 1);
        title.erase(0, title.find_first_not_of(" "));
        title.erase(title.find_last_not_of(" ") + 1);

        //find country
        country = temp.substr(0, temp.find(","));
        temp.erase(0, temp.find(",") + 1);
        country.erase(0, country.find_first_not_of(" "));
        country.erase(country.find_last_not_of(" ") + 1);

        //find price
        price = std::stod(temp.substr(0, temp.find(",")));
        temp.erase(0, temp.find(",") + 1);

        //find year
        year = std::stoi(temp.substr(0, temp.find(",")));
        temp.erase(0, temp.find(",") + 1);

        //find description
        desc = temp;
        desc.erase(0, desc.find_first_not_of(" "));
        desc.erase(desc.find_last_not_of(" ") + 1);

        m_author = author;
        m_title = title;
        m_country = country;
        m_year = year;
        m_price = price;
        m_desc = desc;
    }

    std::ostream& operator<<(ostream& os, const Book& book)
    {
        os.width(20);
        os << book.m_author << " | ";
        os.width(22);
        os << book.title() << " | ";
        os.width(5);
        os << book.country() << " | ";
        os.width(4);
        os << book.year() << " | ";
        os.width(6);
        os.setf(ios::fixed);
        os.precision(2);
        os << book.m_price << " | ";
        os.unsetf(ios::fixed);
        os << book.m_desc << endl;
        return os;
    }

}