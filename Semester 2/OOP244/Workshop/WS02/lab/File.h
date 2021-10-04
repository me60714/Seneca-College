///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.03            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef NAMESPACE_FILE_H_
#define NAMESPACE_FILE_H_

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char filename[]);
   bool read(int &employeeNumber);
   bool read(double &salaryOfEm);
}
#endif