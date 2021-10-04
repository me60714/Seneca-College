///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.05            //
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

   bool read(char postalCode[])
   {
      if (fscanf(fptr, "%[^,],", postalCode) == 1)
      {
         return true;
      }

      return false;
   }

   bool read(int &amount)
   {
      if (fscanf(fptr, "%d\n", &amount) == 1)
      {
         return true;
      }

      return false;
   }
}