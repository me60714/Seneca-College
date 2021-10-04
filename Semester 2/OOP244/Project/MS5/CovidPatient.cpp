///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.24            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "CovidPatient.h"

using namespace std;
namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
      nextCovidTicket++;
   }

   char CovidPatient::type() const {return 'C';}

   istream& CovidPatient::csvRead(istream &istr)
   {
      Patient::csvRead(istr);
      nextCovidTicket = Patient::number() + 1;
      istr.ignore(1000, '\n');
      return istr;
   }

   ostream& CovidPatient::write(ostream &ostr) const
   {
      if (fileIO())
         Patient::csvWrite(ostr);
      else
      {
         ostr << "COVID TEST" << endl;
         Patient::write(ostr);
         ostr << endl;
      }
      return ostr;
   }

   istream& CovidPatient::read(istream &istr)
   {
      if (fileIO())
         csvRead(istr);
      else
         Patient::read(istr);
      
      return istr;
   }

}