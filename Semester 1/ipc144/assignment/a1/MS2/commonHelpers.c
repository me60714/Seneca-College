/*
	==================================================
	Assignment #1 Milestone #1
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/

#include <stdio.h>
#include <time.h>

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

        if (newLine != '\n' || value <= 0)
        {
            printf("ERROR: Value must be a positive integer greater than zero: ");
        }
    } while (newLine != '\n' || value <= 0);

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
    }
    while (value <= 0);

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