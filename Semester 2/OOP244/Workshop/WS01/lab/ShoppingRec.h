///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.05.25            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef NAMESPACE_SHOPPINGREC_H
#define NAMESPACE_SHOPPINGREC_H

const int MAX_TITLE_LENGTH = 50;

struct ShoppingRec
{
    char m_title[MAX_TITLE_LENGTH + 1];
    int m_quantity;
    bool m_bought;
};

namespace sdds
{
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec *shp);
    void toggleBoughtFlag(ShoppingRec *rec);
    bool isShoppingRecEmpty(const ShoppingRec *shp);
}

#endif