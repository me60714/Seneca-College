///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.06            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
namespace sdds {
    class Menu
    {
        char *m_text = nullptr;  // holds the menu content dynamically
        int m_noOfSel; // holds the number of options displayed in menu content
        void display() const;
        void setEmpty();
    public:
        Menu(const char *MenuContent, int NoOfSelections);
        virtual ~Menu();
        int &operator>>(int &Selection);
        // add safe copying logic
        Menu(const Menu& src);

        operator bool()const;
    };
}

#endif