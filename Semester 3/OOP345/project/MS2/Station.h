// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.11.14
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#include <iostream>
namespace sdds
{
    class Station
    {
        int m_id;
        std::string m_name{};
        std::string m_desc{};
        size_t m_nextNum;
        size_t m_stockNum;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const std::string& str);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}