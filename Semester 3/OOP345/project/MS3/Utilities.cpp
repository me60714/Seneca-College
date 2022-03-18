// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.11.14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include "Utilities.h"

namespace sdds
{
    char Utilities::m_delimiter{','};
    
    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        std::string token{};
        size_t position = str.find(m_delimiter, next_pos);

        if (position == next_pos)
        {
            more = false;
            throw "Not found!";
        }
        else if (position != std::string::npos)
        {
            token = str.substr(next_pos, position - next_pos);
            m_widthField = std::max(m_widthField, token.length());
            next_pos = position + 1;
            more = true;
        }
        else if (position == std::string::npos)
        {
            token = str.substr(next_pos, position - next_pos);
            m_widthField = std::max(m_widthField, token.length());
            next_pos = position + 1;
            more = false;
        }
        return token;
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }

}