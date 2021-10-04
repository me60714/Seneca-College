///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.06            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   extern bool debug; // making sdds::debug variable global to all the files
                      // which include: "utils.h"

   int getTime(); // returns the time of day in minutes
   int getInt(const char *prompt = nullptr, char delimiter = '\0');
   int getInt(
      int min,
      int max,
      const char* prompt = nullptr,
      const char* errorMessage = nullptr,
      bool showRangeAtError = true,
      char delimiter = '\0'
   );
   char* getcstr(
      const char* prompt = nullptr,
      std::istream& istr = std::cin,
      char delimiter = '\n'
   );
   void strCpy(char *des, const char *src);
   void strnCpy(char *des, const char *src, int len);
   int strCmp(const char *s1, const char *s2);
   int strnCmp(const char *s1, const char *s2, int len);
   int strLen(const char *s);
   const char *strStr(const char *str1, const char *str2);
   void strCat(char *des, const char *src);
}
#endif // !SDDS_UTILS_H_

