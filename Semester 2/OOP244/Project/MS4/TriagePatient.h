///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.24            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {
    class TriagePatient : public Patient {
        char *m_symptom;

    public:
        TriagePatient();
        char type() const;
        ostream &csvWrite(ostream &ostr) const;
        istream &csvRead(istream &istr);
        ostream &write(ostream &ostr) const;
        istream &read(istream &istr);
        ~TriagePatient();
    };
}
#endif // !SDDS_TRIAGEPATIENT_H


