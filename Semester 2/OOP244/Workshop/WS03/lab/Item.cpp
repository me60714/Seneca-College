///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.10            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

    void Item::setName(const char *name)
    {
        int lengthOfName = strLen(name);
        int endOfName = 0;

        if (lengthOfName < 21)
        {    
            for (int i = 0; i < lengthOfName; i++)
            {
                m_itemName[i] = name[i];
                endOfName++;
            }
            m_itemName[endOfName] = '\0';
        }
        else
        {
            for (int i = 0; i < 21; i++)
            {
                m_itemName[i] = name[i];
            }
            m_itemName[20] = '\0';
        }
        
    }

    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }

    void Item::set(const char *name, double price, bool taxed)
    {
        if (price < 0 || name == nullptr)
            setEmpty();
        else
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display() const
    {

        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(20);
            cout.fill('.');
            cout << m_itemName;
            cout << " | ";
            cout.setf(ios::right);
            cout.width(7);
            cout.fill(' ');
            cout.precision(2);
            cout << fixed;
            cout << m_price;
            cout << " | ";
            cout << ((m_taxed) ? "Yes" : "No ");
            cout << " |" << endl;
            cout.unsetf(ios::right);
        }
        else
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
    }

    bool Item::isValid() const
    {
        if (m_price != 0 && m_itemName[0] != '\0')
        {
            return true;
        }
        
        return false;
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        const double taxrate = 0.13;
        return (m_taxed)? m_price*taxrate : 0.0;
    }
}