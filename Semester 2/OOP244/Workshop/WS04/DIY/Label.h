///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
#define MAX_CONTENT_LENGTH 71
#define FRAME_LENGTH 9
#include <iostream>
namespace sdds{
    class Label{
        char m_content[MAX_CONTENT_LENGTH];
        char m_frame[FRAME_LENGTH];
        int m_length;
        int m_height;
        void setContent(const char* content);
    public:
        void setToEmpty();
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream &printLabel() const;
        std::ostream &printHeaderLabel() const;
        std::ostream &printContentLabel() const;
        std::ostream &printTailerLabel() const;
    };
}

#endif