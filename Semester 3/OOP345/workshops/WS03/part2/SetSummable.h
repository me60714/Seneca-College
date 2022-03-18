// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.30
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <iostream>
#include "Set.h"

namespace sdds
{
    template<size_t N, typename T>
    class SetSummable : public Set<N, T>
    {
        T m_collection[N]{};
        size_t m_current_element{0u};

    public:
        T accumulate(const std::string& filter) const
        {
            T sum(filter);
            for (size_t i = 0; i < this->size(); i++)
            {
                if (this->get(i).isCompatibleWith(sum))
                    sum += this->get(i);
            }
            return sum;
        }
    };
}