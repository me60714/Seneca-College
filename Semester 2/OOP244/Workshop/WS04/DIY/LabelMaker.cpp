///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "LabelMaker.h"
#include "cstring.h"
#include "Label.h"
using namespace std;
namespace sdds
{
    void LabelMaker::setEmpty()
    {   
        m_labels = nullptr;
    }

    LabelMaker::LabelMaker(int noOfLabels)
    {
        m_labels = new Label[noOfLabels];
        
        for (int i = 0; i < noOfLabels; i++)
            m_labels[i].setToEmpty();

        m_noOfLabels =noOfLabels;
    }

    void LabelMaker::readLabels()
    {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << i + 1 << endl;
            m_labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_labels[i].printLabel();
            cout << endl;
        }
    }

    LabelMaker::~LabelMaker()
    {
        delete[] m_labels;
        m_labels = nullptr;
    }   
}