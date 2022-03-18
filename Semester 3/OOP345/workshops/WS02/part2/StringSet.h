// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
// try to use pragma once here

#include <iostream>

namespace sdds
{
    class StringSet
    {
        std::string* m_elements{nullptr};
        unsigned int m_count = 0;
    public:
        StringSet();
        StringSet(const std::string& fname);
        StringSet(const StringSet& str); //copy constructor
        StringSet& operator=(const StringSet& str); //copy assignment
        ~StringSet();
        size_t size() const;
        std::string operator[](size_t size);
        StringSet(StringSet&& str); //move constructor
        StringSet& operator=(StringSet&& str); //move assignment
    };
}