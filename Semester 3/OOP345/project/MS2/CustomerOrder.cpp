// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.11.29
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds
{
    size_t CustomerOrder::m_widthField = 0;

    //default constructor
    CustomerOrder::CustomerOrder(){};

    //a custom 1-arg constructor
    CustomerOrder::CustomerOrder(const std::string str)
    {
        if (!str.empty())
        {
            Utilities u;
            size_t p = 0;
            bool more = false;
            std::string temp;

            m_name = u.extractToken(str, p, more);
            m_product = u.extractToken(str, p, more);

            temp = str.substr(p, str.length() - p);
            m_cntItem = (std::count(temp.begin(), temp.end(), u.getDelimiter())) + 1;

            m_lstItem = new Item *[m_cntItem];
            for (size_t i = 0; i < m_cntItem; i++)
            {
                m_lstItem[i] = new Item(u.extractToken(str, p, more));
            }

            m_widthField = (m_widthField < u.getFieldWidth()) ? u.getFieldWidth() : m_widthField;
        }
    }
    
    //a copy constructor (throw an exception if called)
    CustomerOrder::CustomerOrder(const CustomerOrder&)
    {
        throw std::string("Copy is not allowed!");
    }

    //a move constructor
    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
    {
        *this = std::move(src);
    }

    //a move assignment operator
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
    {
        if (this != &src)
        {
            if (m_lstItem)
            {
                for(size_t i = 0; i < m_cntItem; i++){delete m_lstItem[i];}
                delete[] m_lstItem;
            }
            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;
            m_lstItem = src.m_lstItem;
            src.m_name = "";
            src.m_product = "";
            src.m_cntItem = 0;
            src.m_lstItem = nullptr;
        }
        return *this;
    }

    //a destructor
    CustomerOrder::~CustomerOrder()
    {
        for (size_t i = 0; i < m_cntItem; i++){delete m_lstItem[i];}
        delete[] m_lstItem;
        m_lstItem = nullptr;
    }


    bool CustomerOrder::isFilled() const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (!m_lstItem[i]->m_isFilled)
            {return false;}
        }
        return true;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == itemName)
            {return m_lstItem[i]->m_isFilled;}
        }
        return true;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os)
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (station.getItemName() == m_lstItem[i]->m_itemName)
            {
                if (station.getQuantity() > 0)
                {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled " << m_name << ", ";
                    os << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
                else
                {
                    os << "Unable to fill " << m_name << ", ";
                    os << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const
    {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << std::left << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName;
            os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }

}