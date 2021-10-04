///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.15            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "IOAble.h"

using namespace std;
namespace sdds {
    IOAble::IOAble()
    {
        m_height_ = 0;
        m_width_ = 0;
        csv_ = false;
    }

    // std::ostream& IOAble::csvWrite(std::ostream& ostr) const
    // {
    //     return ostr << m_height_ << "," << m_width_;
    // }

    // std::istream& IOAble::csvRead(std::istream& istr)
    // {
    //     istr >> m_height_;
    //     istr.ignore();
    //     istr >> m_width_;
    //     istr.ignore();
    //     return istr;
    // }

    // std::ostream& IOAble::write(std::ostream& ostr) const
    // {
    //     if (csv_)
    //     {
    //         csvWrite(ostr);
    //     }
    //     else
    //     {
    //         cout << "IOAble" << endl;
    //         int i;
    //         for (int j = 0; j < m_height_; j++)
    //         {
    //             for (i = 0; i < m_width_ * 2; i++, ostr << "*")
    //                 ;
    //             ostr << endl;
    //         }
    //     }
    //     return ostr;
    // }

    // std::istream& IOAble::read(std::istream& istr)
    // {
    //     if (csv_)
    //     {
    //         csvRead(istr);
    //     }
    //     else
    //     {
    //         cout << "Height: ";
    //         istr >> m_height_;
    //         cout << "Width: ";
    //         istr >> m_width_;
    //     }
    //     return istr;
    // }

    IOAble::~IOAble()
    {
        ;
    }

    std::ostream &operator<<(std::ostream &ostr, const IOAble &ioa) {return ioa.write(ostr);}
    std::istream &operator>>(std::istream &istr, IOAble &ioa) {return ioa.read(istr);}

}