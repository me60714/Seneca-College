// ===================================================================================
//  Assignment: 1
//  Milestone : 4
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#include <stdio.h>
#include <time.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

int oldestyear;
int youngestyear;
struct Demographic demographic = {0};
struct Account account = {0};
struct UserLogin login = {{0}};

void getAccount(struct Account *account)
{
    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    printf("Enter the account number: ");
    account->num_account = getInteger();
    printf("\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    account->type_account = getCharOption("AC");

    printf("\n");
}

void getUserLogin(struct UserLogin *userlogging)
{
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");

    printf("Enter user login (10 chars max): ");
    getCString(userlogging->name_login, 3, 10);

    printf("Enter the display name (30 chars max): ");
    getCString(userlogging->name_account, 3, 30);

    printf("Enter the password (must be 8 chars in length): ");
    getCString(userlogging->password, 8, 8);

    printf("\n");
}

void getDemographic(struct Demographic *demo)
{
    printf("Demographic Data Input\n");
    printf("----------------------------------------\n");

    printf("Enter birth year (current age must be between 18 and 110): ");
    oldestyear = currentYear() - 110;
    youngestyear = currentYear() - 18;
    demo->year_birth = getIntFromRange(oldestyear, youngestyear);

    printf("Enter the household Income: $");
    demo->income = getPositiveDouble();

    printf("Enter the country (30 chars max.): ");
    getCString(demo->country, 3, 30);

    printf("\n");
}

void updateAccount(struct Account *account)
{

    int selection, out = 0;

    do
    {
        printf("Account: %d - Update Options\n", account->num_account);
        printf("----------------------------------------\n");
        printf("1) Update account type (current value: %c)\n", account->type_account);
        printf("2) Login\n");
        printf("3) Demographics\n");
        printf("0) Done\n");
        printf("Selection: ");

        selection = getIntFromRange(0, 3);
        printf("\n");

        if (selection == 1)
        {
            printf("Enter the account type (A=Agent | C=Customer): ");
            account->type_account = getCharOption("AC");
            printf("\n");
            out = 0;
        }
        else if (selection == 2)
        {
            updateUserLogin(&account->logging);
            out = 0;
        }
        else if (selection == 3)
        {
            updateDemographic(&account->demo);
            out = 0;
        }
        else if (selection == 0)
        {
            out = 1;
        }
    } while (out != 1);
}

void updateUserLogin(struct UserLogin *userlogging)
{
    int selection, out = 0;

    do
    {
        printf("User Login: %s - Update Options\n", userlogging->name_login);
        printf("----------------------------------------\n");
        printf("1) Display name (current value: %s)\n", userlogging->name_account);
        printf("2) Password\n");
        printf("0) Done\n");
        printf("Selection: ");

        selection = getIntFromRange(0, 2);
        printf("\n");

        if (selection == 1)
        {
            printf("Enter the display name (30 chars max): ");
            getCString(userlogging->name_account, 3, 30);
            printf("\n");
            out = 0;
        }
        else if (selection == 2)
        {
            printf("Enter the password (must be 8 chars in length): ");
            getCString(userlogging->password, 8, 8);
            printf("\n");
            out = 0;
        }
        else if (selection == 0)
        {
            out = 1;
        }
    } while (out == 0);
}

void updateDemographic(struct Demographic *demo)
{
    int selection, out = 0;

    do
    {
        printf("Demographic Update Options\n");
        printf("----------------------------------------\n");
        printf("1) Household Income (current value: $%.2lf)\n", demo->income);
        printf("2) Country (current value: %s)\n", demo->country);
        printf("0) Done\n");
        printf("Selection: ");

        selection = getIntFromRange(0, 2);
        printf("\n");

        if (selection == 1)
        {
            printf("Enter the household Income: $");
            demo->income = getPositiveDouble();
            printf("\n");
            out = 0;
        }
        else if (selection == 2)
        {
            printf("Enter the country (30 chars max.): ");
            getCString(demo->country, 3, 30);
            printf("\n");
            out = 0;
        }
        else if (selection == 0)
        {
            out = 1;
        }
    } while (out == 0);
}