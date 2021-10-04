///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.15            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>
using namespace std;

namespace sdds{
    class IOAble{
        int m_height_, m_width_;
    public:
        bool csv_;
        IOAble();
        virtual ostream& csvWrite(ostream& ostr) const = 0;
        virtual istream& csvRead(istream& istr) = 0;
        virtual ostream& write(ostream& ostr) const = 0;
        virtual istream& read(istream& istr) = 0;
        virtual ~IOAble();
    };
    std::ostream& operator<<(std::ostream& ostr, const IOAble& ioa);
    std::istream& operator>>(std::istream& istr, IOAble& ioa);
}


#endif