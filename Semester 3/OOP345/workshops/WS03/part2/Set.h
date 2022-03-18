// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.30
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <iostream>

namespace sdds
{
    template<size_t N, typename T>
    class Set
    {
        size_t m_current_element{0u};
        T m_collection[N]{};

    public:
        size_t size() const { return m_current_element; }

        const T &get(size_t idx) const { return m_collection[idx]; }

        void operator+=(const T& item)
        {
            if (m_current_element < N)
            {
                m_collection[m_current_element] = item;
                m_current_element++;
            }
        }
    };
}