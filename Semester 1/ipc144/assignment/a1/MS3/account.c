// ===================================================================================
//  Assignment: 1
//  Milestone : 3
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