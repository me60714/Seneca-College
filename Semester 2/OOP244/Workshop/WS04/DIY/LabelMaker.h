///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LABALMAKER_H_
#define SDDS_LABALMAKER_H_
#include <iostream>
#include "Label.h"
namespace sdds{
    class LabelMaker {
        Label* m_labels;
        int m_noOfLabels;
        void setEmpty();
    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}

#endif