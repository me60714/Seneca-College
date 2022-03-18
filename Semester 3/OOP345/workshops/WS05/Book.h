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
    class Book
    {
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_year{0};
        double m_price{0};
        std::string m_desc{};
    public:
        Book();
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();
        Book(const std::string& strBook);
        friend std::ostream& operator<<(std::ostream& os, const Book& book);

        template <typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_desc);
        }
    };
}