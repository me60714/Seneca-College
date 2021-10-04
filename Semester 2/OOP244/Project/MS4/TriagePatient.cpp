///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.24            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "TriagePatient.h"
#include "utils.h"

namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
      m_symptom = nullptr;
      nextTriageTicket++;
   }

   char TriagePatient::type() const {return 'T';}

   ostream& TriagePatient::csvWrite(ostream& ostr) const
   {
      Patient::csvWrite(ostr);
      ostr << "," << m_symptom;
      return ostr;
   }

   istream& TriagePatient::csvRead(istream& istr)
   {
      if (m_symptom != nullptr)
      {
         delete[] m_symptom;
         m_symptom = nullptr;
      }

      Patient::csvRead(istr);
      istr.ignore();
      m_symptom = getcstr(nullptr, istr, '\n');
      istr.ignore(); ///////
      nextTriageTicket = Patient::number() + 1;

      return istr;
   }

   ostream& TriagePatient::write(ostream& ostr) const
   {
      if (fileIO())
         csvWrite(ostr);
      else
      {
         ostr << "TRIAGE" << endl;
         Patient::write(ostr);
         ostr << endl;
         ostr << "Symptoms: " << m_symptom << endl;
      }
      return ostr;
   }

   istream& TriagePatient::read(istream &istr)
   {
      if (fileIO())
      {
         csvRead(istr);
      }
      else
      {
         if (m_symptom != nullptr)
            delete [] m_symptom;
         
         Patient::read(istr);
         m_symptom = getcstr("Symptoms: ", istr, '\n');
         istr.ignore(); //////
      }
      return istr;
   }

   TriagePatient::~TriagePatient()
   {
      delete [] m_symptom;
      m_symptom = nullptr;
   }
}