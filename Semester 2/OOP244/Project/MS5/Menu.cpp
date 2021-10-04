///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.06            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds {
    void Menu::display() const {
        if (m_text)
        {
            cout << m_text << endl;
            cout << "0- Exit" << endl;
        }
    }

    void Menu::setEmpty(){
        m_noOfSel = 0;
        m_text = nullptr;
    }

    Menu::Menu(const char *MenuContent, int NoOfSelections) {
        m_text = new char[strLen(MenuContent) + 1];
        strCpy(m_text, MenuContent);
        m_noOfSel = NoOfSelections;
    }

    Menu::~Menu(){
        delete [] m_text;
        m_text = nullptr;
    }

    Menu::Menu(const Menu& src){
        if (this->m_text != src.m_text && src)
        {
            setEmpty();
            m_text = new char[strLen(src.m_text) + 1];
            strCpy(m_text, src.m_text);
            m_noOfSel = src.m_noOfSel;
        }
    }

    int& Menu::operator>>(int& Selection) {
        display();
        Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true, '\n');
        return Selection;
    }

    Menu::operator bool() const{
        bool empty = (m_noOfSel == 0 && m_text == nullptr);
        return (!empty)? true:false;
    }
}