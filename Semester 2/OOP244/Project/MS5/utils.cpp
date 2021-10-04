///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.06            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
   bool debug = false; // made global in utils.h
   int getTime()
   {
      int mins = -1;
      if (debug)
      {
         Time t(0);
         cout << "Enter current time: ";
         do
         {
            cin.clear();
            cin >> t; // needs extraction operator overloaded for Time
            if (!cin)
            {
               cout << "Invlid time, try again (HH:MM): ";
               cin.clear();
            }
            else
            {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else
      {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char *prompt, char delimiter)
   {
      if (prompt != nullptr)
         cout << prompt;

      char value[100];
      bool realInt = false;
      do
      {
         cin.clear();
         cin.get(value, 100, delimiter);
         if (!((value[0] >= '0' && value[0] <= '9') || value[0] == '-'))
         {
            cout << "Bad integer value, try again: ";
            cin.clear();
         }
         else
         {
            bool notInt = false;
            for (unsigned int i = 0; i < strlen(value); i++)
            {
               if (!(value[i] >= '0' && value[i] <= '9') || value[strlen(value) - 1] == ' ')
                  notInt = true;

               if (value[0] == '-')
                  notInt = false;
            }

            if (notInt)
            {
               cout << "Enter only an integer, try again: ";
               cin.clear();
            }
            else
               realInt = true;
         }
         cin.ignore();

      } while (!realInt);

      return stoi(value);
   }

   int getInt(int min, int max, const char *prompt, const char *errorMessage, bool showRangeAtError, char delimiter)
   {
      int value;
      bool properValue = false;

      do
      {
         value = getInt(prompt, delimiter);
         if (value < min || value > max)
         {
            cout << errorMessage;
            prompt = nullptr;

            if (showRangeAtError)
            {
               cout << "[" << min << " <= value <= " << max << "]: ";
               prompt = nullptr;
            }
         }
         else
            properValue = true;

      } while (!properValue);

      return value;
   }

   char* getcstr(const char *prompt, std::istream &istr, char delimiter)
   {
      if (prompt != nullptr)
         cout << prompt;

      char temp[1000];
      istr.get(temp, 1000, delimiter);
      char* cstr = new char[strlen(temp) + 1];
      strCpy(cstr, temp);
      
      return cstr;
   }

   void strCpy(char *des, const char *src)
   {
      while (*src != '\0')
      {
         *des = *src;
         des++;
         src++;
      }

      *des = '\0';
   };

   void strnCpy(char *des, const char *src, int len)
   {
      int srclen = strLen(src);

      if (srclen == len)
      {
         while (*src != '\0')
         {
            *des = *src;
            des++;
            src++;
         }
      }
      else if (srclen > len)
      {
         int i = 0;
         for (i = 0; i < len; i++)
         {
            *des = *src;
            des++;
            src++;
         }
      }
      else if (srclen < len)
         strCpy(des, src);
   };

   int strCmp(const char *s1, const char *s2)
   {
      while (*s1 == *s2 && *s1 != '\0')
      {
         s1++;
         s2++;
      }

      return *s1 - *s2;
   }

   int strnCmp(const char *s1, const char *s2, int len)
   {
      if (strLen(s2) < len)
      {
         int i = 0;
         for (i = 0; i < len; i++)
         {
            s1++;
            s2++;
         }
      }
      else if (strLen(s2) == len)
      {
         while (*s1 == *s2 && *s1 != '\0')
         {
            s1++;
            s2++;
         }
      }

      return *s1 - *s2;
   }

   int strLen(const char *s)
   {
      int i = 0;
      while (s[i] != '\0')
      {
         i++;
      }

      return i;
   }

   const char *strStr(const char *str1, const char *str2)
   {
      while (*str1 != '\0' && *str2 != '\0')
      {
         const char *found = str1;
         const char *str3 = str2;

         while (*str1 != '\0' && *str3 != '\0' && *str1 == *str3)
         {
            str1++;
            str3++;
         }

         if (*str3 == '\0')
         {
            return found;
         }

         str1 = found + 1;
      }

      return 0;
   }

   void strCat(char *des, const char *src)
   {
      int i = 0, j = 0;
      char combineString[100];

      while (des[i] != '\0')
      {
         combineString[j] = des[i];
         i++;
         j++;
      }

      i = 0;
      while (src[i] != '\0')
      {
         combineString[j] = src[i];
         i++;
         j++;
      }

      combineString[j] = '\0';

      strCpy(des, combineString);
   }
}