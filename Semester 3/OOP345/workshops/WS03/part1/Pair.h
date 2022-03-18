// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.29
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <iostream>

namespace sdds{
    template<typename V, typename K>
    class Pair{
        V val_{};
        K key_{};
    public:
        Pair()
        {
            ;
        }

        Pair(const K& key, const V& val)
        {
            key_ = key;
            val_ = val;
        }

        const V& value() const {return val_;}

        const K& key() const {return key_;}

        void display(std::ostream& os) const {os << key_ << " : " << val_ << std::endl;}

        // Pair<V, K>& operator+=(const Pair<V, K>& vk)
        // {
        //     *this = Pair(vk.key_, vk.val_);
        //     return *this;
        // }
    };

    // template<>
    // Pair<std::string, std::string>& Pair<std::string, std::string>::operator+=(const Pair<std::string, std::string>& vk)
    // {



    //     return *this;
    // }

    template <typename V, typename K>
    std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
    {
        pair.display(os);
        return os;
    }
}