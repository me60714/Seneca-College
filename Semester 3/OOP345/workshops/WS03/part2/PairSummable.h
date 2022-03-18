// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.30
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <iostream>
#include <iomanip>
#include "Pair.h"

namespace sdds
{
    template<typename V, typename K>
    class PairSummable : public Pair<V, K>
    {
        static V initial;
        static size_t m_MinWidth;

    public:
        PairSummable(){}
        
        PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value)
        {
            if (m_MinWidth < key.size())
            {
                m_MinWidth = key.size();
            }
        }

        bool isCompatibleWith(const PairSummable<V, K>& b) const
        {
            return this->key() == b.key();
        }

        PairSummable<V, K>& operator+=(const PairSummable<V, K>& src)
        {
            *this = PairSummable(this->key(), this->value() + src.value());
            return *this;
        }

        void display(std::ostream& os) const
        {
            os << std::left;
            os << std::setw(m_MinWidth);
            Pair<V, K>::display(os);
            os << std::right;
        }
    };

    template <typename V, typename K>
    size_t PairSummable<V, K>::m_MinWidth = 0;

    template <typename V, typename K>
    V PairSummable<V, K>::initial;

    template <>
    PairSummable<std::string, std::string> &PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string> &src)
    {
        if (value() == "")
        {
            *this = PairSummable(this->key(), src.value());
        }
        else
        {
            *this = PairSummable(this->key(), this->value() + ", " + src.value());
        }
        return *this;
    }
}