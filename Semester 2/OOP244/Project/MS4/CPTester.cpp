// CovidPatient Tester
// file: CPTester.cpp
// Version: 1.0
// Date: 2021-06-23
// Author: Fardad
// Description:
// This file tests the CovidPatient Module of your project
/////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "Patient.h"
#include "CovidPatient.h"
#include "utils.h"
using namespace sdds;
int main() {
   sdds::debug = true;
   CovidPatient A, B;
   cout << "Testing CovidPatient:" << endl
      << "Enter the following:" << endl
      << "Enter current time: 12:34" << endl
      << "Name: aaa" << endl
      << "OHIP: 111111111" << endl;
   A.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   A.fileIO(false);
   cin >> A;
   cout << "Enter the following:" << endl
      << "Enter current time: 12:35" << endl
      << "Name: bbb" << endl
      << "OHIP: 222222222" << endl;
   B.setArrivalTime();
   cout << "Enter Patient information:" << endl;
   B.fileIO(false);
   cin >> B;
   cout << endl << "Patients information entered:" << endl;
   cout << A << endl << B << endl;
   A.fileIO(true);
   B.fileIO(true);
   cout << "CSV output: " << endl;
   cout << A << endl << B << endl << endl;
   cout << "Testing CSV input:" << endl
      << "Enter the following:" << endl;
   cout << ">ccc,333333333,10,23:45" << endl << ">";
   cin >> A;
   cout << endl << "Data entered:" << endl;
   A.fileIO(false);
   cout << A << endl;
   cout << "Testing global ticket number variable:" << endl
      << "Enter the following: " << endl
      << "Enter current time: 23:55" << endl
      << "Name: ddd" << endl
      << "OHIP: 444444444" << endl;
   CovidPatient C;
   C.setArrivalTime();
   C.fileIO(false);
   cin >> C;
   cout << "Patient information entered:" << endl;
   cout << C << endl;

   return 0;
}