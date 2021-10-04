///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.05.28            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "cstring.h"

namespace sdds
{

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

    void strnCpy(char *des, char *src, int len)
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

    int strnCmp(const char *s1, char *s2, int len)
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

    int strLen(char *s)
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