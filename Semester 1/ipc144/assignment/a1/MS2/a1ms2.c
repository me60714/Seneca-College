// ===================================================================================
//  Assignment: 1
//  Milestone : 2
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"       // *** DO NOT MODIFY THIS LINE ***
#include "commonHelpers.h" // *** DO NOT MODIFY THIS LINE ***
#include <time.h>

// ------------------------------------------------------------------
// Function Prototypes:

// Confirm MS1 stuff still works and grades can be applied to MS1
void commonHelpersTest(void); // *** DO NOT MODIFY THIS LINE ***

// Display Account details                              // *** DO NOT MODIFY THIS PROTOTYPE ***
void displayAccount(const struct Account account, const struct UserLogin login, const struct Demographic demo);

// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    struct Account account = {0};         // *** DO NOT MODIFY THIS LINE ***
    struct UserLogin login = {{0}};       // *** DO NOT MODIFY THIS LINE ***
    struct Demographic demographic = {0}; // *** DO NOT MODIFY THIS LINE ***

    // Declare other variables you may need here:
    int oldestyear;
    int youngestyear;

    printf("Assignment 1 Milestone 2\n");                        // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n\n"); // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Confirm MS1 deliverables - Test commonHelper functions
    // ---------------------------------------------------------
    commonHelpersTest(); // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data: get user input
    // ---------------------------------------------------------
    printf("Account Data Input\n");                       // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each Account member:

    printf("Enter the account number: ");
    account.num_account = getInteger();

    printf("Enter the account type (A=Agent | C=Customer): ");
    account.type_account = getCharOption("AC");

    printf("\n");

    // ---------------------------------------------------------
    // UserLogin Data: get user input
    // ---------------------------------------------------------
    printf("User Login Data Input\n");                    // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each UserLogin member:
    printf("Enter user login (10 chars max): ");

    getCString(login.name_login, 3, 10);

    printf("Enter the display name (30 chars max): ");

    getCString(login.name_account, 3, 30);

    printf("Enter the password (must be 8 chars in length): ");

    getCString(login.password, 8, 8);

    printf("\n");

    // ---------------------------------------------------------
    // Demographic Data: get user input
    // ---------------------------------------------------------
    printf("Demographic Data Input\n");                   // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each Demographic member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    //       when prompting for the birth year data.  There is a function in the
    //       commonHelpers library that gives you this!

    printf("Enter birth year (current age must be between 18 and 110): ");

    oldestyear = currentYear() - 110;
    youngestyear = currentYear() - 18;

    demographic.year_birth = getIntFromRange(oldestyear, youngestyear);

    printf("Enter the household Income: $");

    demographic.income = getPositiveDouble();

    printf("Enter the country (30 chars max.): ");

    getCString(demographic.country, 3, 30);

    printf("\n");

    // ---------------------------------------------------------
    // Display all the entered data
    // ---------------------------------------------------------

    // Call function to display the Account record (see function prototype above and definition below):
    //________________(__________________________________________);
    displayAccount(account, login, demographic);

    printf("\n");

    printf("\nAssignment #1 Milestone #2 completed!\n"); // *** DO NOT MODIFY THIS LINE ***

    return 0; // *** DO NOT MODIFY THIS LINE ***
}

// ------------------------------------------------------------------
// Function definitions:

// Display Account details: Add the missing code!
void displayAccount(const struct Account account, const struct UserLogin login, const struct Demographic demo)
{
    // Give this formatting to the student
    printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
    printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");

    // Display the respective data to align to the table header above:

    if (account.type_account == 'A')
    {
        printf("%05d AGENT     %5d $%10.2lf %-10s %-15s %-10s %8s", account.num_account, demo.year_birth, demo.income, demo.country, login.name_account, login.name_login, login.password);
    }
    else if (account.type_account == 'C')
    {
        printf("%05d CUSTOMER  %5d $%10.2lf %-10s %-15s %-10s %8s", account.num_account, demo.year_birth, demo.income, demo.country, login.name_account, login.name_login, login.password);
    }
}

// Confirm MS1 stuff still works so grades may be applied to MS1
// *** DO NOT MODIFY THIS FUNCTION DEFINITION ***
void commonHelpersTest(void)
{
    int intValue;
    double dblValue;
    char charValue, cstringValue[7];

    printf("TEST #1: Enter the word 'error' [ENTER], then the number -100: ");
    intValue = getInteger();
    if (intValue == -100)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #2: Enter the number -100 [ENTER], then the number 200: ");
    intValue = getPositiveInteger();
    if (intValue == 200)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #3: Enter the number -4 [ENTER], then 12 [ENTER], then -3: ");
    intValue = getIntFromRange(-3, 11);
    if (intValue == -3)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #4: Enter the word 'error' then, the number -150.75: ");
    dblValue = getDouble();
    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #5: Enter the number -22.11 [ENTER], the number 225.55: ");
    dblValue = getPositiveDouble();
    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #6: Enter the word 'error' then, the number 11: ");
    intValue = getIntFromRange(-3, 11);
    if (intValue == 11)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #7: Enter the character 'R' [ENTER], then 'p' [ENTER], then 'r': ");
    charValue = getCharOption("qwerty");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }

    printf("TEST #8: Enter the word 'horse' [ENTER], then 'SENECA': ");
    getCString(cstringValue, 6, 6);
    printf("Your Result: %s (Answer: SENECA)\n\n", cstringValue);

    printf("TEST #9: Enter the words 'Seneca College' [ENTER], then 'IPC': ");
    getCString(cstringValue, 3, 6);
    printf("Your Result: %s (Answer: IPC)\n\n", cstringValue);

    printf("TEST #10: Enter the words 'ipc' [ENTER], then 'SCHOOL': ");
    getCString(cstringValue, 4, 6);
    printf("Your Result: %s (Answer: SCHOOL)\n\n", cstringValue);
}
