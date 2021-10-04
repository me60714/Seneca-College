///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Label.h"
#include "cstring.h"
#define HEIGHT_OF_LABEL 3
#define DEFAULT_FRAME "+-+|+-+|"
using namespace std;
namespace sdds
{
    void Label::setToEmpty()
    {
        m_content[0] = '\0';
        m_length = 0;
        m_height = 0;
    }

    void Label::setContent(const char *content)
    {
        if (content != nullptr && strLen(content) <= MAX_CONTENT_LENGTH)
        {
            m_content[0] = '\0';
            strCpy(m_content, content);
        }
        else
            cout << "content invalid" << endl;
    }

    Label::Label()
    {
        setToEmpty();
        strCpy(m_frame, DEFAULT_FRAME);
    }
    
    Label::Label(const char *frameArg)
    {
        setToEmpty();
        strCpy(m_frame, frameArg);
    }
    
    Label::Label(const char *frameArg, const char *content)
    {
        setToEmpty();
        strCpy(m_frame, frameArg);
        setContent(content);
        m_height = HEIGHT_OF_LABEL;
        m_length = strLen(content) + 2;
    }
    
    Label::~Label()
    {
        m_frame[0] = '\0';
        m_content[0] = '\0';
        m_height = 0;
        m_length = 0;
    }
    
    void Label::readLabel()
    {
        cout << "> ";
        cin.getline(m_content, MAX_CONTENT_LENGTH);
    }
    
    std::ostream &Label::printLabel() const
    {
        if (m_content[0] != '\0')
        {
            printHeaderLabel();
            printContentLabel();
            printTailerLabel();
        }
        return cout;
    }

    std::ostream &Label::printHeaderLabel() const
    {
        cout << m_frame[0];
        cout.width(strLen(m_content) + 3);
        cout.fill(m_frame[1]);
        cout << m_frame[2] << endl;
        return cout;
    }
    
    std::ostream &Label::printContentLabel() const
    {
        cout << m_frame[7];
        cout.fill(' ');
        cout.width(strLen(m_content) + 3);
        cout << m_frame[3] << endl;

        cout << m_frame[7];
        cout << " ";
        cout.width(strLen(m_content));
        cout << m_content;
        cout << " ";
        cout << m_frame[3] << endl;

        cout << m_frame[7];
        cout.width(strLen(m_content) + 3);
        cout.fill(' ');
        cout << m_frame[3] << endl;

        return cout;
    }
    
    std::ostream &Label::printTailerLabel() const
    {
        cout << m_frame[6];
        cout.width(strLen(m_content) + 3);
        cout.fill(m_frame[5]);
        cout << m_frame[4];
        return cout;
    }
}