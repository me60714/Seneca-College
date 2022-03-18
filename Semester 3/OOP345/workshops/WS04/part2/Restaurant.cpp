// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 07.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Restaurant.h"

using namespace std;

namespace sdds
{
    //default constructor
    Restaurant::Restaurant(){}

    //one argument constructor
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
    {
        if (reservations != nullptr)
        {
            m_resNum = cnt;
            m_reservation = new Reservation[m_resNum];
            for (size_t i = 0; i < m_resNum; i++){m_reservation[i] = *reservations[i];}
        }
    }

    //destructor
    Restaurant::~Restaurant()
    {
        delete[] m_reservation;
        m_reservation = nullptr;
    }

    //copy constructor
    Restaurant::Restaurant(const Restaurant& rest){*this = rest;}

    //copy assignment
    Restaurant& Restaurant::operator=(const Restaurant& rest)
    {
        if (this != &rest)
        {
            delete[] m_reservation;
            m_reservation = nullptr;

            m_resNum = rest.m_resNum;
            
            m_reservation = new Reservation[m_resNum];
            for (size_t i = 0; i < m_resNum; i++)
            {
                m_reservation[i] = rest.m_reservation[i];
            }
        }
        return *this;
    }

    //move constructor
    Restaurant::Restaurant(Restaurant&& rest){*this = move(rest);}

    //move assignment
    Restaurant& Restaurant::operator=(Restaurant&& rest)
    {
        if (this != &rest)
        {
            delete[] m_reservation;
            m_reservation = nullptr;
            m_resNum = rest.m_resNum;
            rest.m_resNum = 0;
            m_reservation = rest.m_reservation;
            rest.m_reservation = nullptr;
        }

        return *this;
    }

    size_t Restaurant::size() const {return m_resNum;}

    ostream& operator<<(ostream& os, const Restaurant& rest)
    {
        static size_t CALL_CNT = 0;
        CALL_CNT++;

        os << "--------------------------" << endl;
        os << "Fancy Restaurant (" << CALL_CNT << ")" << endl;
        os << "--------------------------" << endl;

        if (rest.size() == 0)
        {
            os << "This restaurant is empty!" << endl;
        }
        else
        {
            for (size_t i = 0; i < rest.size(); i++)
            {
                os << rest.m_reservation[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }

}