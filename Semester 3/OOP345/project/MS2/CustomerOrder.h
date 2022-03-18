// Name: Wei-Chih Kao
// Seneca Student ID: 158000190
// Seneca email: wkao3@myseneca.ca
// Date of completion: 2021.11.29
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"

namespace sdds
{
    class CustomerOrder
    {
        struct Item
        {
            std::string m_itemName;
            size_t m_serialNumber{0};
            bool m_isFilled{false};

            Item(const std::string& src) : m_itemName(src){};
        };

        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{0};
        Item** m_lstItem{nullptr};
        static size_t m_widthField;

    public:
        //default constructor
        CustomerOrder();
        //a custom 1-arg constructor
        CustomerOrder(const std::string str);
        //the copy operator= should be deleted.
        CustomerOrder& operator=(const CustomerOrder&) = delete;
        //a copy constructor (throw an exception if called)
        CustomerOrder(const CustomerOrder&);
        //a move constructor
        CustomerOrder(CustomerOrder&& src) noexcept;
        //a move assignment operator
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;
        //a destructor
        ~CustomerOrder();

        bool isFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}



#endif