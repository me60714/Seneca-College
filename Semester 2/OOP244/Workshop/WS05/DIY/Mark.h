///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.28            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;
        char* m_grade;
        double m_scale;
        bool m_bool;
    public:
        Mark();
        Mark(int mark);
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator+=(int mark);
        Mark& operator=(int mark);
    };
    int& operator+=(int& val, const Mark& mark);
}
#endif