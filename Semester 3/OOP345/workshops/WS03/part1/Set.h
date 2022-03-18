// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.29
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once

#include <iostream>

namespace sdds {
    template<size_t N, typename T>
    class Set {
        static size_t current_element;
        T collection[N];
    public:

        size_t size() const {return current_element;}

        const T& get(size_t idx) const {return collection[idx];}

        void operator+=(const T& item) {
            if (current_element < N)
            {
                collection[current_element] = item;
                current_element++;
            }
        }
    };

    template <size_t N, typename T>
    size_t Set<N, T>::current_element = 0u;
}