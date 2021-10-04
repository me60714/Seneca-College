// ===================================================================================
//
//  Assignment:  1
//  Milestone:   1
//  Description: Main logic/tester
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |
// +---------------------------------------------------------+
//
//                         HOWEVER....
//
// In the development of your solution, you can...
// -----------------------------------------------
// - Comment out the lines of code which call a function you have not yet developed
//   (See each tester function definition to see where you can do this)
// - Uncomment the lines of code previously commented to return the file to its
//   original state so you may fully test your solution.
//
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "commonHelpers.h"

// -----------------------------------------
// Function Prototypes
void test01_getInteger(void);
void test02_getPositiveInteger(void);
void test03_getIntFromRange(void);
void test04_getIntFromRange(void);
void test05_getDouble(void);
void test06_getPositiveDouble(void);
void test07_getCharOption(void);
void test08_getCString(void);
void test09_getCString(void);
void test10_getCString(void);

// -----------------------------------------
// Main: Entry-point to the application
int main(void)
{
    printf("Assignment 1 Milestone 1\n");
    printf("=============================================\n\n");

    // -----------------------------------------
    // Unit Tests:

    // Integer testers
    test01_getInteger();
    test02_getPositiveInteger();
    test03_getIntFromRange();
    test04_getIntFromRange();

    // Double testers
    test05_getDouble();
    test06_getPositiveDouble();

    // Char tester
    test07_getCharOption();

    // C string testers
    test08_getCString();
    test09_getCString();
    test10_getCString();

    printf("Assignment #1 Milestone #1 completed!\n");

    return 0;
}

// -----------------------------------------
// Function Definitions

void test01_getInteger(void)
{
    int intValue = 999;

    printf("TEST #1: Enter the word 'error' [ENTER], then the number -100: ");

    // You may want to comment the next line if you have not yet created the getInteger function:
    intValue = getInteger();

    if (intValue == -100)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test02_getPositiveInteger(void)
{
    int intValue = 999;

    printf("TEST #2: Enter the number -100 [ENTER], then the number 200: ");

    // You may want to comment the next line if you have not yet created the getPositiveInteger function:
    intValue = getPositiveInteger();

    if (intValue == 200)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test03_getIntFromRange(void)
{
    int intValue = 999;

    printf("TEST #3: Enter the word 'error' [ENTER], then the number -4 [ENTER], then 12 [ENTER], then -3: ");

    // You may want to comment the next line if you have not yet created the getIntFromRange function:
    intValue = getIntFromRange(-3, 11);

    if (intValue == -3)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test04_getIntFromRange(void)
{
    int intValue = 999;

    printf("TEST #4: Enter the number 14: ");

    // You may want to comment the next line if you have not yet created the getIntFromRange function:
    intValue = getIntFromRange(-40, 14);

    if (intValue == 14)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test05_getDouble(void)
{
    double dblValue = 999.0;

    printf("TEST #5: Enter the word 'error' then, the number -150.75: ");

    // You may want to comment the next line if you have not yet created the getDouble function:
    dblValue = getDouble();

    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test06_getPositiveDouble(void)
{
    double dblValue = 999.0;

    printf("TEST #6: Enter the number -22.11 [ENTER], the number 225.55: ");

    // You may want to comment the next line if you have not yet created the getPositiveDouble function:
    dblValue = getPositiveDouble();

    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test07_getCharOption(void)
{
    char charValue = 'x';

    printf("TEST #7: Enter the character 'R' [ENTER], then 'p' [ENTER], then 'r': ");

    // You may want to comment the next line if you have not yet created the getCharOption function:
    charValue = getCharOption("qwerty");

    if (charValue == 'r')
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test08_getCString(void)
{
    char cstringValue[7] = {'\0'};

    printf("TEST #8: Enter the word 'horse' [ENTER], then 'SENECA': ");

    // You may want to comment the next line if you have not yet created the getCString function:
    getCString(cstringValue, 6, 6);

    printf("Your Result: %s (Answer: SENECA)\n\n", cstringValue);
}

void test09_getCString(void)
{
    char cstringValue[7] = {'\0'};

    printf("TEST #9: Enter the words 'Seneca College' [ENTER], then 'IPC': ");

    // You may want to comment the next line if you have not yet created the getCString function:
    getCString(cstringValue, 3, 6);

    printf("Your Result: %s (Answer: IPC)\n\n", cstringValue);
}

void test10_getCString(void)
{
    char cstringValue[7] = {'\0'};

    printf("TEST #10: Enter the words 'ipc' [ENTER], then 'SCHOOL': ");

    // You may want to comment the next line if you have not yet created the getCString function:
    getCString(cstringValue, 4, 6);

    printf("Your Result: %s (Answer: SCHOOL)\n\n", cstringValue);
}
