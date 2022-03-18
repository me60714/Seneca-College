// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.11.14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const std::string& str)
    {
        Utilities U;
        bool more = false;
        size_t position = 0;

        m_id = ++id_generator;
        m_name = U.extractToken(str, position, more);
        m_nextNum = stoi(U.extractToken(str, position, more));
        m_stockNum = stoi(U.extractToken(str, position, more));
        (m_widthField < U.getFieldWidth()) ? m_widthField = U.getFieldWidth() : 1;
        m_desc = U.extractToken(str, position, more) ;
    }

    const std::string& Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_nextNum++;
    }

    size_t Station::getQuantity() const
    {
        return m_stockNum;
    }

    void Station::updateQuantity()
    {
        if (m_stockNum > 0)
            m_stockNum--;
    }

    void Station::display(std::ostream& os, bool full) const
    {
        os << '[' << std::setw(3) << std::setfill('0') << std::right << m_id << "] ";
        os << "Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
        os << " [" << std::setw(6) << std::setfill('0') << std::right << m_nextNum << "]";
        
        os << std::setfill(' ') << std::left;
        
        if (full)
        {
            os << " Quantity: " << std::setw(m_widthField) << m_stockNum;
            os << " Description: " << m_desc;
        }
        os << std::endl;
    }

}