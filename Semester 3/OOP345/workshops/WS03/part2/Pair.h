// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.30
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <iostream>

namespace sdds
{
    template<typename V, typename K>
    class Pair
    {
        V m_val{};
        K m_key{};
    public:
        Pair() : m_val{}, m_key{}
        {
            ;
        }

        Pair(const K &key, const V &val) : m_val{val}, m_key{key}
        {
            ;
        }

        const V& value() const {return m_val;}

        const K& key() const { return m_key; }

        virtual void display(std::ostream& os) const { os << m_key << " : " << m_val << std::endl; }
    };

    template <typename V, typename K>
    std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
    {
        pair.display(os);
        return os;
    }
}