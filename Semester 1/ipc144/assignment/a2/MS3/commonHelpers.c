/*
	==================================================
	Assignment #2 Milestone #3
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

// Uses the time.h library to obtain current year information // Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing
    }
}

int getInteger(void)
{
    int value;
    char newLine = 'x';

    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
    }
    return value;
}

int getPositiveInteger(void)
{
    int value;
    char newLine = 'x';

    do
    {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n' || value < 0)
        {
            printf("ERROR: Value must be positive or zero: ");
        }
    } while (newLine != '\n' || value < 0);

    return value;
}

double getDouble(void)
{
    double value;
    char newLine = 'x';

    while (newLine != '\n')
    {
        scanf("%lf%c", &value, &newLine);

        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
    }
    return value;
}

double getPositiveDouble(void)
{
    double value;

    do
    {
        value = getDouble();
        if (value <= 0)
        {
            printf("ERROR: Value must be a positive double floating-point number: ");
        }
    } while (value <= 0);

    return value;
}

int getIntFromRange(int lower_bound, int upper_bound)
{
    int value;
    value = getInteger();

    while (value < lower_bound || value > upper_bound)
    {
        printf("ERROR: Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
        value = getInteger();
    }
    return value;
}

char getCharOption(const char *l_validChart)
{
    char value;
    char newLine = 'x';
    int keepgoing = 0;

    do
    {
        scanf("%c%c", &value, &newLine);
        if (newLine == '\n')
        {
            int i;
            for (i = 0; l_validChart[i] != '\0' && !keepgoing; i++)
            {
                if (l_validChart[i] == value)
                {
                    keepgoing = 1;
                }
            }
        }
        else
        {
            clearStandardInputBuffer();
        }
        if (keepgoing == 0)
            printf("ERROR: Character must be one of [%s]: ", l_validChart);

    } while (keepgoing == 0);

    return value;
}

void getCString(char *cstring, int minNum_chart, int maxNum_chart)
{
    int length;
    char newLine = 'x';
    int keepgoing = 1;

    do
    {
        scanf("%256[^\n]%c", cstring, &newLine);

        int i;
        for (i = 0; cstring[i] != '\0'; i++)
        {
        }

        length = i;

        // printf("%d\n", length);

        if (length != minNum_chart && minNum_chart == maxNum_chart)
        {
            printf("ERROR: String length must be exactly %d chars: ", minNum_chart);
            keepgoing = 1;
        }
        else if (length > maxNum_chart)
        {
            printf("ERROR: String length must be no more than %d chars: ", maxNum_chart);
            keepgoing = 1;
        }
        else if (length < minNum_chart)
        {
            printf("ERROR: String length must be between %d and %d chars: ", minNum_chart, maxNum_chart);
            keepgoing = 1;
        }
        else if (length <= maxNum_chart && length >= minNum_chart)
            keepgoing = 0;

    } while (keepgoing == 1);
}

// void getCString(char *cstring, int minNum_chart, int maxNum_chart)
// {
//     int length;
//     char newLine = 'x';
//     int keepgoing = 1;

//     do
//     {
//         scanf("%256[^\n]%c", cstring, &newLine);

//         int i, j;
//         for (i = 0; cstring[i] != '\0'; i++)
//         {
//         }

//         length = i;

//         for (j = 0; j < i; j++)
//         {
//             if (isblank(cstring[j]) && maxNum_chart <= 10)
//             {
//                 printf("ERROR: The user login must NOT contain whitespace characters.");
//                 keepgoing = 1;
//             }
//             else if (length != minNum_chart && minNum_chart == maxNum_chart)
//             {
//                 passwordsecurity(cstring);

//                 if (passwordsecurity(cstring) == 1)
//                     printf("ERROR: String length must be exactly %d chars: ", minNum_chart);

//                 keepgoing = 1;
//             }
//             else if (length > maxNum_chart)
//             {
//                 printf("ERROR: String length must be no more than %d chars: ", maxNum_chart);
//                 keepgoing = 1;
//             }
//             else if (length < minNum_chart)
//             {
//                 printf("ERROR: String length must be between %d and %d chars: ", minNum_chart, maxNum_chart);
//                 keepgoing = 1;
//             }
//             else if (length <= maxNum_chart && length >= minNum_chart)
//                 keepgoing = 0;
//         }

//     } while (keepgoing == 1);
// }

int passwordsecurity(char *string)
{
    int pass = 0, i, countdigit = 0, countuppercase = 0, countlowercase = 0, countsymbol = 0;
    char symbol[9] = "!@#$%^&*";

    for (i = 0; i < strlen(string); i++)
    {
        if (isdigit(string[i]))
            countdigit++;

        if (islower(string[i]))
            countlowercase++;

        if (isupper(string[i]))
            countuppercase++;

        int j;
        for (j = 0; j < 9; j++)
        {
            if (string[i] == symbol[j])
                countsymbol++;
        }
    }

    if (countdigit >= 2 && countlowercase >= 2 && countuppercase >= 2 && countsymbol >= 2)
    {
        pass = 1;
    }
    else
    {
        puts("SECURITY: Password must contain 2 of each:");
        puts("          Digit: 0-9");
        puts("          UPPERCASE character");
        puts("          lowercase character");
        puts("          symbol character: !@#$%^&*");

        pass = 0;
    }

    return pass;
}

int whitespace(char *string)
{
    int pass = 0, i, space = 0;

    for (i = 0; i < strlen(string); i++)
    {
        if (isblank(string[i]))
            space++;
    }

    if (space >= 1)
    {
        pass = 1;
        puts("ERROR: The user login must NOT contain whitespace characters.");
    }
    else
        pass = 0;

    return pass;
}