// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Oct. 13.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#include <iostream>
#include <string>

namespace sdds
{
    class Movie
    {
        std::string m_title{};
        int m_year{0};
        std::string m_desc{};
    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);

        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_desc);
        };
        
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    };
}