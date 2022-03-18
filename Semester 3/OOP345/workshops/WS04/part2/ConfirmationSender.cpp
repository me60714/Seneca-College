// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 07.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
    //default constructor
    ConfirmationSender::ConfirmationSender(){}

    //destructor
    ConfirmationSender::~ConfirmationSender()
    {
        delete[] m_reservation;
        m_reservation = nullptr;
    }

    //copy constructor
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& con){*this = con;}

    //copy assignment
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& con)
    {
        if (this != &con)
        {
            delete[] m_reservation;
            m_reservation = nullptr;

            m_resNum = con.m_resNum;
            
            m_reservation = new const Reservation*[m_resNum];
            for (size_t i = 0; i < m_resNum; i++)
            {
                m_reservation[i] = con.m_reservation[i];
            }
        }
        return *this;
    }

    //move constructor
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& con){*this = move(con);}

    //move assignment
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& con)
    {
        if (this != &con)
        {
            delete[] m_reservation;
            m_reservation = nullptr;

            m_resNum = con.m_resNum;
            con.m_resNum = 0;
            m_reservation = con.m_reservation;
            con.m_reservation = nullptr;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
    {
        bool exist = false;
        for (size_t i =0; i < m_resNum && !exist; i++)
        {
            if (&res == m_reservation[i]){exist = true;}
        }

        if (!exist)
        {
            const Reservation** temp = new const Reservation* [m_resNum + 1];
            for (size_t i = 0; i < m_resNum; i++)
            {
                temp[i] = m_reservation[i];
            }
            temp[m_resNum] = &res;
            m_resNum++;
            delete[] m_reservation;
            m_reservation = temp;
        }
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
    {
        bool exist = false;
        
        for (size_t i = 0; i < m_resNum && !exist; i++)
        {
            if (&res == m_reservation[i])
            {
                m_reservation[i] = nullptr;
                exist = true;
                m_resNum--;
            }
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream& os, const ConfirmationSender& con)
    {
        os << "--------------------------" << endl;
        os << "Confirmations to Send" << endl;
        os << "--------------------------" << endl;

        if (con.m_resNum == 0)
        {
            os << "There are no confirmations to send!\n";
        }
        else
        {
            for (size_t i = 0; i < con.m_resNum; i++)
            {
                if (con.m_reservation[i] != nullptr)
                {
                    os << *con.m_reservation[i];
                }
            }
        }
        os << "--------------------------\n";
        return os;
    }

}