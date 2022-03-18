// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021.09.24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "StringSet.h"

using namespace std;

namespace sdds
{
    StringSet::StringSet()
    {
        m_elements = nullptr;
        m_count = 0;
    }

    StringSet::StringSet(const std::string &fname)
    {
        m_count = 0;
        std::ifstream fin(fname);
        string fstring;

        if (fin.is_open())
        {
            while (getline(fin, fstring, ' '))
            {
                m_count++;
            }

            m_elements = new string[m_count];
            fin.clear();
            fin.seekg(0);

            for (unsigned int i = 0; i < m_count; i++)
            {
                getline(fin, m_elements[i], ' ');
            }

            fin.close();
        }
        else
        {
            m_elements = nullptr;
            m_count = 0;
        }
    }

    StringSet::StringSet(const StringSet &str) //copy constructor
    {
        m_count = str.m_count;
        *this = str;
    }
    StringSet &StringSet::operator=(const StringSet &str) //copy assignment
    {
        if (this != &str)
        {
            m_count = str.m_count;

            delete[] m_elements;
            m_elements = nullptr;

            if (str.m_elements)
            {
                m_elements = new string[m_count];
                for (unsigned int i = 0; i < m_count; i++)
                {
                    m_elements[i] = str.m_elements[i];
                }
            }
        }

        return *this;
    }

    StringSet::~StringSet()
    {
        delete[] m_elements;
        m_elements = nullptr;
    }

    size_t StringSet::size() const { return m_count; }

    std::string StringSet::operator[](size_t index)
    {
        std::string temp;

        if (index >= 0 && index < m_count)
        {
            temp = m_elements[index];
            return temp;
        }
        else
        {
            return "";
        }
    }

    StringSet::StringSet(StringSet&& str)  //move constructor
    {
        m_count = str.m_count;
        *this = std::move(str);
    }

    StringSet& StringSet::operator=(StringSet&& str) //move assignment
    {
        if (this != &str)
        {
            m_count = str.m_count;
            str.m_count = 0;
            delete[] m_elements;
            m_elements = str.m_elements;
            str.m_elements = nullptr;
        }
        return *this;
    }
}