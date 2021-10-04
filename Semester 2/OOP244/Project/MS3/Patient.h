///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.15            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
    class Patient : public IOAble {
        char* m_nameOfPatient;
        int m_OHIPNumber;
        Ticket T;
        bool m_fileIOFlag;
    public:
        Patient(int ticketNumber, bool IOFlag);
        ~Patient();
        virtual char type() const = 0;
        bool fileIO() const;
        void fileIO(bool IOFlag);
        bool operator==(char c) const;
        bool operator==(const Patient& p) const;

        void setArrivalTime();
        operator Time() const;
        int number() const;
        ostream &csvWrite(ostream &ostr) const;
        istream &csvRead(istream &istr);
        ostream &write(ostream &ostr) const;
        istream &read(istream &istr);
    };
}

#endif