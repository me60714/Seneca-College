///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.24            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds {
    class CovidPatient : public Patient {
    public:
        CovidPatient();
        char type() const;
        istream &csvRead(istream &istr);
        ostream &write(ostream &ostr) const;
        istream &read(istream &istr);
    };


}
#endif // !SDDS_COVIDPATIENT_H_



