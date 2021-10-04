///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.05.25            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef NAMESPACE_SHOPPINGLIST_H
#define NAMESPACE_SHOPPINGLIST_H

namespace sdds
{
    bool loadList();
    bool saveList();
    void removeItem(int index);
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
    void displayList();
    void removeBoughtItems();
}

#endif