///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.08            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "cstring.h"
namespace sdds {
    void strCpy(char *des, const char *src)
    {
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }

        *des = '\0';
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