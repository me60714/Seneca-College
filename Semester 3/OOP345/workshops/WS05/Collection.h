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
    template <typename T>
    class Collection
    {
        std::string m_name{};
        T* m_items{};
        size_t m_size{0};
        void (*observer)(const Collection<T>&, const T&){nullptr};

    public:
        Collection(const std::string& name){m_name = name;}

        //delete copy operations
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;

        ~Collection()
        {
            delete[] m_items;
            m_items = nullptr;
        };

        const std::string& name() const {return m_name;};

        size_t size() const {return m_size;};

        void setObserver(void (*observer)(const Collection<T>&, const T&)){this->observer = observer;};

        Collection<T>& operator+=(const T& item)
        {
            bool flag = false;
            for (size_t i = 0u; i < m_size; i++)
            {
                if (m_items[i].title() == item.title())
                {
                    flag = true;
                }
            }

            if (!flag)
            {
                T* temp = new T[m_size + 1];
                for (size_t i = 0u; i < m_size; i++)
                {
                    temp[i] = m_items[i];
                }

                temp[m_size] = item;
                delete[] m_items;
                m_items = temp;
                m_size++;

                if (observer != nullptr)
                {
                    observer(*this, m_items[m_size - 1]);
                }
            }
            return *this;
        };

        T& operator[](size_t idx) const
        {
            std::string errMsg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";

            if (idx >= m_size)
            {
                throw std::out_of_range(errMsg);
            }
            else
            {
                return m_items[idx];
            }
        }

        T* operator[](const std::string& title) const
        {
            for (size_t i = 0u; i < m_size; i++)
            {
                if (m_items[i].title() == title)
                {
                    return &(m_items[i]);
                }
            }

            return nullptr;
        };

        friend std::ostream &operator<<(std::ostream& os, const Collection& col)
        {
            for (size_t i = 0; i < col.size(); i++)
            {
                os << col[i];
            }
            return os;
        }
    };
}