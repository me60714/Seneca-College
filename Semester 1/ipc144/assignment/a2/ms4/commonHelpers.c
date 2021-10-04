/*
	==================================================
	Assignment #2 Milestone #4
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
#include <stdlib.h>

// A2-MS4: Sample Output commands
char cmds[300][100] = {
    "1",
    "30004",
    "cust2",
    "77*&FFaa7",
    "30004",
    "cust2",
    "TT*&21tt",
    "30004",
    "cust3",
    "77*&FFaa",
    "1",
    "30005",
    "cust2",
    "77*&FFaa",
    "30004",
    "cust2",
    "77*&FFaa",
    "1",
    "4",
    "80004",
    "60001",
    "80020",
    "0",
    "2",
    "Funny Noises are coming from the unit!",
    "Funny Noise!",
    "When it turns on it screams at me and it's quite offending.",
    "4",
    "0",
    "2",
    "3",
    "80004",
    "3",
    "80020",
    "2",
    "I'm so confused.",
    "1",
    "Double broken!",
    "2",
    "0",
    "3",
    "60001",
    "3",
    "Y",
    "N",
    "3",
    "80600",
    "3",
    "Y",
    "Y",
    "Never mind, I oiled it and all is fine now.",
    "4",
    "80600",
    "0",
    "3",
    "30530",
    "3",
    "Y",
    "3",
    "80600",
    "4",
    "80020",
    "0",
    "0",
    "1",
    "50008",
    "agentJ",
    "TT*&21tt",
    "11",
    "12",
    "1",
    "3",
    "34063",
    "y",
    "Y",
    "1",
    "C",
    "NobodyWillKnowMe",
    "Nobody Will Know Me",
    "No Body",
    "HarryHorse",
    "Horse and goat and donkey get along",
    "Nay to Hay",
    "abcdefg",
    "aaJJ88$#a",
    "aJJ77$#J",
    "aaJ99$#c",
    "aaJJ8$#@",
    "aaJJ77*(",
    "aaJJ88$#",
    "2004",
    "1910",
    "2003",
    "asdf",
    "-8.22",
    "0.00",
    "125000.12",
    "Not all countries get along unfortunately",
    "u.s.a.",
    "2",
    "53070",
    "1",
    "c",
    "C",
    "2",
    "1",
    "Wylie Coyote",
    "2",
    "dd99@$FF",
    "0",
    "3",
    "1",
    "0",
    "180222.22",
    "2",
    "canada",
    "0",
    "0",
    "5",
    "6",
    "80599",
    "0",
    "7",
    "70533",
    "0",
    "8",
    "64611",
    "0",
    "3",
    "20020",
    "Y",
    "4",
    "5",
    "7",
    "0",
    "8",
    "0",
    "1",
    "C",
    "CrazyCamel",
    "Sandy Sand",
    "12RR!@jj",
    "1911",
    "54321.22",
    "Australia",
    "5",
    "9",
    "80600",
    "1",
    "2",
    "3",
    "N",
    "0",
    "8",
    "0",
    "9",
    "80600",
    "3",
    "Y",
    "1",
    "Enjoy your purchase!",
    "2",
    "Y",
    "Y",
    "Ticket is now closed.",
    "0",
    "8",
    "80600",
    "0",
    "9",
    "70533",
    "1",
    "0",
    "9",
    "80204",
    "2",
    "Y",
    "N",
    "0",
    "9",
    "80020",
    "2",
    "Y",
    "0",
    "9",
    "70533",
    "3",
    "0",
    "9",
    "60001",
    "3",
    "N",
    "3",
    "Y",
    "0",
    "7",
    "60001",
    "0",
    "10",
    "Y",
    "3",
    "30001",
    "Y",
    "3",
    "50599",
    "Y",
    "3",
    "30004",
    "Y",
    "3",
    "34000",
    "Y",
    "3",
    "53007",
    "Y",
    "3",
    "30014",
    "Y",
    "3",
    "70021",
    "Y",
    "3",
    "35035",
    "Y",
    "3",
    "82042",
    "Y",
    "3",
    "35049",
    "Y",
    "3",
    "54056",
    "Y",
    "5",
    "11",
    "12",
    "0",
    "0",
    "y"};
int cmds_length = 239;
int cmds_counter = 0;
int debug = 1;

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

    if (debug && cmds_counter < cmds_length)
    {
        value = atoi(cmds[cmds_counter++]);
        printf("%d\n", value);
        return value;
    }
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

    if (debug && cmds_counter < cmds_length)
    {
        value = atoi(cmds[cmds_counter++]);
        printf("%d\n", value);
        return value;
    }
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

    if (debug && cmds_counter < cmds_length)
    {
        while (1)
        {
            int i = 0;
            int cmdisdigit = 1;

            for (i = 0; i < strlen(cmds[cmds_counter]); i++)
            {
                if (!isdigit(cmds[cmds_counter][i]) && cmds[cmds_counter][i] != '.' && cmds[cmds_counter][i] != '-')
                    cmdisdigit = 0;
            }

            if (cmdisdigit)
            {
                value = atof(cmds[cmds_counter++]);

                char zero[] = "0";

                // printf("\ncmds[cmds_counter - 1] = %s\n", cmds[cmds_counter - 1]);

                if (strcmp(zero, cmds[cmds_counter - 1]) == 0)
                {
                    printf("%s\n", cmds[cmds_counter - 1]);
                    break;
                }

                printf("%.2lf\n", value);
                break;
            }
            else
            {
                printf("%s\n", cmds[cmds_counter]);
                printf("ERROR: Value must be a double floating-point number: ");
                cmds_counter++;
            }
        }
        return value;
    }

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

    if (debug && cmds_counter < cmds_length)
    {

        do
        {
            value = cmds[cmds_counter++][0];
            printf("%c\n", value);
            // scanf("%c%c", &value, &newLine);
            // if (newLine == '\n')
            // {
            int i;
            for (i = 0; l_validChart[i] != '\0' && !keepgoing; i++)
            {
                if (l_validChart[i] == value)
                {
                    keepgoing = 1;
                }
            }
            // }
            // else
            // {
            //     clearStandardInputBuffer();
            // }
            if (keepgoing == 0)
                printf("ERROR: Character must be one of [%s]: ", l_validChart);

        } while (keepgoing == 0);

        return value;
        // return value;
    }
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

    if (debug && cmds_counter < cmds_length)
    {
        do
        {
            strcpy(cstring, cmds[cmds_counter++]);
            printf("%s\n", cstring);

            int i;
            for (i = 0; cstring[i] != '\0'; i++)
            {
            }

            length = i;

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
        return;
    }
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
        puts("ERROR:  The user login must NOT contain whitespace characters.");
    }
    else
        pass = 0;

    return pass;
}