///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.06            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time &Time::setToNow(){
        m_min = getTime();
        return* this;
    }

    Time::Time(unsigned int min){
        if (min >= 0)
            m_min = min;
        else
            m_min = 0;
    }
    
    std::ostream& Time::write(std::ostream& ostr) const{
        int HH = 0, MM = 0;
        if (m_min >= 0)
        {
            MM = m_min % 60;
            HH = m_min / 60;
            ostr.width(2);
            ostr.fill('0');
            ostr << HH << ":";
            ostr.width(2);
            ostr.fill('0');
            ostr << MM;
        }
        return ostr;
    }

    std::istream& Time::read(std::istream& istr){
        int HH = 0, MM = 0;
        char separated;
        istr >> HH;
        istr >> separated;
        istr >> MM;
        
        if (istr && HH >= 0 && MM >= 0 && separated == ':')
            m_min = HH * 60 + MM;
        else
            istr.setstate(ios::failbit);

        return istr;
    }

    Time& Time::operator-=(const Time &D){
        if (m_min >= (unsigned)int(D))
            m_min -= int(D);
        else
        {
            int day = 0;
            day = int(D) / 24 / 60;
            m_min = m_min + (24 * 60) * (day + 1) - int(D);
        }
        return *this;
    }

    Time Time::operator-(const Time &D) const{
        Time temp;
        temp.m_min = m_min;

        if (temp.m_min >= (unsigned)int(D))
            temp -= D;
        else
        {
            int day = 0;
            day = int(D) / 24 / 60;
            temp.m_min = temp.m_min + (24 * 60) * (day + 1) - int(D);
        }
        return temp;
    }

    Time &Time::operator+=(const Time &D){
        m_min = m_min + int(D);
        return *this;
    }

    Time Time::operator+(const Time &D) const{
        Time temp;
        temp.m_min = m_min;
        temp += D;
        return temp;
    }

    Time& Time::operator=(unsigned int val){
        m_min = val;
        return *this;
    }

    Time& Time::operator*=(unsigned int val){
        m_min *= val;
        return *this;
    }

    Time& Time::operator/=(unsigned int val){
        m_min /= val;
        return *this;
    }

    Time Time::operator*(unsigned int val) const{
        return Time(m_min * val);
    }

    Time Time::operator/(unsigned int val) const{
        return Time(m_min / val);
    }

    Time::operator unsigned int() const{ return m_min; }

    Time::operator int() const { return int(m_min); }

    std::ostream &operator<<(std::ostream &ostr, const Time &D){ return D.write(ostr); }

    std::istream &operator>>(std::istream &istr, Time &D){ return D.read(istr); }
}