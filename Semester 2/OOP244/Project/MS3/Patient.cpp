///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.15            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Patient.h"
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds {
    Patient::Patient(int ticketNumber, bool IOFlag) : T(ticketNumber)
    {
        m_nameOfPatient = nullptr;
        m_fileIOFlag = IOFlag;
    }

    Patient::~Patient()
    {
        delete [] m_nameOfPatient;
        m_nameOfPatient = nullptr;
    }

    bool Patient::fileIO() const {return m_fileIOFlag;}

    void Patient::fileIO(bool IOFlag) {m_fileIOFlag = IOFlag;}

    bool Patient::operator==(char c) const {return (c == type())? true : false;}

    bool Patient::operator==(const Patient &p) const {return (this->type() == p.type())? true : false;}

    void Patient::setArrivalTime() {T.resetTime();}

    Patient::operator Time() const {return T.operator sdds::Time();}

    int Patient::number() const {return T.number();}

    ostream& Patient::csvWrite(ostream &ostr) const
    {
        ostr << type() << "," << m_nameOfPatient << "," << m_OHIPNumber << ",";
        T.csvWrite(ostr);
        return ostr;
    }

    istream& Patient::csvRead(istream &istr)
    {
        if (m_nameOfPatient != nullptr){
            delete [] m_nameOfPatient;
        }

        m_nameOfPatient = getcstr(nullptr, istr, ',');
        istr.ignore(100, ',');
        istr >> m_OHIPNumber;
        istr.ignore(100, ',');
        return T.csvRead(istr);
    }

    ostream& Patient::write(ostream &ostr) const
    {
        if (m_fileIOFlag)
            csvWrite(ostr);
        else
        {
            ostr << T << endl;
            
            if (strLen(m_nameOfPatient) <= 25)
                ostr << m_nameOfPatient;
            else
            {
                for (int i = 0; i < 25; i++)
                    ostr << m_nameOfPatient[i];
            }

            ostr << ", OHIP: " << m_OHIPNumber;
        }
        return ostr;
    }

    istream& Patient::read(istream &istr)
    {
        if (m_fileIOFlag)
            csvRead(istr);
        else
        {
            char* temp = nullptr;
            cout << "Name: ";
            temp = getcstr("", istr, '\n');
            istr.ignore();
            delete [] m_nameOfPatient;
            m_nameOfPatient = new char[strLen(temp) + 1];
            strCpy(m_nameOfPatient, temp);
            delete [] temp;
            cout << "OHIP:";
            m_OHIPNumber = getInt(100000000, 999999999, "", "Invalid OHIP Number, ", true, '\n');
        }
        
        return istr;
    }

}