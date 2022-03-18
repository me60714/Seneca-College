// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 07.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include "Reservation.h"

namespace sdds
{
    class ConfirmationSender
    {
        const Reservation** m_reservation{};
        size_t m_resNum{};
    public:
        //default constructor
        ConfirmationSender();
        //destructor
        ~ConfirmationSender();
        //copy constructor
        ConfirmationSender(const ConfirmationSender& con);
        //copy assignment
        ConfirmationSender &operator=(const ConfirmationSender& con);
        //move constructor
        ConfirmationSender(ConfirmationSender&& con);
        //move assignment
        ConfirmationSender &operator=(ConfirmationSender&& con);
        
        ConfirmationSender &operator+=(const Reservation& res);
        ConfirmationSender &operator-=(const Reservation& res);
        friend std::ostream &operator<<(std::ostream& os, const ConfirmationSender& con);
    };
}