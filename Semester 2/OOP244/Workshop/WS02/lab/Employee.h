///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.03            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef NAMESPACE_EMPLOYEE_H_
#define NAMESPACE_EMPLOYEE_H_

#define DATAFILE "employees.csv"

#include "File.h"

namespace sdds {

   struct Employee {
      char* m_name;
      int m_empNo;
      double m_salary;
   };
   //sorts the dynamic array of employees based on the GPA of the employees.
   void sort();
   // loads a employee structue with its values from the file
   bool load(Employee &listOfEm);
   // allocates the dynamic array of employees and loads all the file
   // records into the array
   bool load();

   // TODO: Declare the prototype for the display function that
   // displays a employee record on the screen:
   void display(const Employee &employee);

   // TODO: Declare the prototype for the display function that 
   // first sorts the employees then displays all the employees on the screen
   void display();
   
   // TODO: Declare the prototype for the deallocateMemory function that
   // first will deallocate all the names in the employee elements
   // then it will deallocate the employee array
   void deallocateMemory();
}
  
#endif