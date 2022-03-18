// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 13.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include <string>

const int SIZE = 6;
namespace sdds
{
    class SpellChecker
    {
        std::string m_badWords[SIZE]{};
        std::string m_goodWords[SIZE]{};
        int m_replace[SIZE]{};

    public:
        SpellChecker();
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}