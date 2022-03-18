// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 05.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
namespace sdds
{
    class Reservation
    {
        std::string m_id{};
        std::string m_name{};
        std::string m_email{};
        int m_numOfPpl{0};
        int m_day{0};
        int m_hour{0};
    
    public:
        Reservation();
        void update(int day, int time);
        Reservation(const std::string& str);
        friend std::ostream& operator<<(std::ostream& os, const Reservation& Res);
    };
}