///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.12            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds 
{
     class CalorieList
    {
        Food* foodInfo;
        int noOfFood;
        int foodAdd;
        int totalcalories() const;
        void title() const;
        void footer() const;
        void setEmpty();
        bool isValid() const;
    public:
        void init(int size);
        bool add(const char *foodName, int calories, int when);
        void display() const;
        void deallocate();
    };
}

#endif