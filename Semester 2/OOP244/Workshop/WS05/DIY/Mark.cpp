///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.28            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
    Mark::Mark()
    {
        m_mark = 0;
        m_grade = (char*)"F";
        m_scale = 0.0;
        m_bool = true;
    }
    Mark::Mark(int mark)
    {
        if (mark >100 || mark < 0)
        {
            m_mark = 0;
            m_grade = (char *)"X";
            m_scale = 0.0;
            m_bool = false;
        }
        else if (mark < 50 && mark >= 0)
        {
            m_mark = mark;
            m_grade = (char *)"F";
            m_scale = 0.0;
            m_bool = true;
        }
        else if (mark < 60 && mark >= 50)
        {
            m_mark = mark;
            m_grade = (char *)"D";
            m_scale = 1.0;
            m_bool = true;
        }
        else if (mark < 70 && mark >= 60)
        {
            m_mark = mark;
            m_grade = (char *)"C";
            m_scale = 2.0;
            m_bool = true;
        }
        else if (mark < 80 && mark >= 70)
        {
            m_mark = mark;
            m_grade = (char *)"B";
            m_scale = 3.0;
            m_bool = true;
        }
        else if (mark <= 100 && mark >= 80)
        {
            m_mark = mark;
            m_grade = (char *)"A";
            m_scale = 4.0;
            m_bool = true;
        }
    }
    Mark::operator int() const { return m_mark; }
    Mark::operator double() const { return m_scale; }
    Mark::operator char() const { return *m_grade; }
    Mark &Mark::operator+=(int val)
    {
        if (m_bool && m_mark + val >= 0 && m_mark + val <= 100) {
            m_mark += val;
            *this = m_mark;
        }
        else if (m_bool) {
            m_mark = 0;
            *this = m_mark;
        }

        return *this;
    }
    Mark &Mark::operator=(int val)
    {
        if (val > 0 && val <= 100){
            m_mark = val;
            if (m_mark < 50 && m_mark >= 0)
            {
                m_grade = (char *)"F";
                m_scale = 0.0;
                m_bool = true;
            }
            else if (m_mark < 60 && m_mark >= 50)
            {
                m_grade = (char *)"D";
                m_scale = 1.0;
                m_bool = true;
            }
            else if (m_mark < 70 && m_mark >= 60)
            {
                m_grade = (char *)"C";
                m_scale = 2.0;
                m_bool = true;
            }
            else if (m_mark < 80 && m_mark >= 70)
            {
                m_grade = (char *)"B";
                m_scale = 3.0;
                m_bool = true;
            }
            else if (m_mark <= 100 && m_mark >= 80)
            {
                m_grade = (char *)"A";
                m_scale = 4.0;
                m_bool = true;
            }
        }
        else{
            m_mark = 0;
            m_grade = (char *)"X";
            m_scale = 0.0;
            m_bool = false;
        }
        return *this;
    }
    int& operator+=(int &val, const Mark &mark) {
        if (int(mark) <= 100 && int(mark) >= 0)
            val += int(mark);

        return val;
    }
}