///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.03            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE *fptr;

   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords()
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1)
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile()
   {
      if (fptr)
         fclose(fptr);
   }

   bool read(char filename[])
   {
      if (fscanf(fptr, "%[^\n]\n", filename) == 1)
      {
         return true;
      }

      return false;
   }

   bool read(int &employeeNumber)
   {
      if (fscanf(fptr, "%d,", &employeeNumber) == 1)
      {
         return true;
      }

      return false;
   }

   bool read(double &salaryOfEm)
   {
      if (fscanf(fptr, "%lf,", &salaryOfEm) == 1)
      {
         return true;
      }

      return false;
   }

}