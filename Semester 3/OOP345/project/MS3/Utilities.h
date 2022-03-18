// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.11.14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once
#include <iostream>
namespace sdds
{
    class Utilities
    {
        size_t m_widthField{1};
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}