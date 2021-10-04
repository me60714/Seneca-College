///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.10            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const
    {
        bool b;

        if (m_title[0] != '\0' && m_items != NULL)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (m_items[i].price() == 0)
                {
                    b = false;
                }
                else
                    b = true;
            }
        }
        else
            b = false;

        return b;
    }

    double Bill::totalTax() const
    {
        double sum = 0.0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            sum += m_items[i].tax();
        }

        return sum;
    }

    double Bill::totalPrice() const
    {
        double sum = 0.0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            sum += m_items[i].price();
        }

        return sum;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;

        if (isValid())
        {
            cout << "| ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
        }
        else
            cout << "| Invalid Bill                         |" << endl;

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;

        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.precision(2);
            cout.setf(ios::right);
            cout.width(10);
            cout << fixed << totalTax() << " |" << endl;

            cout << "|              Total Price: ";
            cout.precision(2);
            cout.setf(ios::right);
            cout.width(10);
            cout << fixed << totalPrice() << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.precision(2);
            cout.setf(ios::right);
            cout.width(10);
            cout << fixed << totalTax() + totalPrice() << " |" << endl;
        }
        else
            cout << "| Invalid Bill                         |" << endl;

        cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char *title, int noOfItems)
    {
        int lengthOfTitle = strLen(title);
        
        if (title[0] == '\0' || noOfItems <= 0)
            setEmpty();
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;

            if (lengthOfTitle <= 36)
            {
                for (int i = 0; i < lengthOfTitle; i++ )
                {
                    strCpy(&m_title[i], &title[i]);
                }
            }

            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char *item_name, double price, bool taxed)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }

        return false;
    }

    void Bill::display() const
    {
        Title();

        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    void Bill::deallocate()
    {                
        delete[] m_items;
        m_items = nullptr;
    }
}