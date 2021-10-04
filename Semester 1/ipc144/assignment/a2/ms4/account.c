// ===================================================================================
//  Assignment: 2
//  Milestone : 4
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

int oldestyear;
int youngestyear;
struct Demographic demographic = {0};
struct Account account = {0};
struct UserLogin login = {{0}};

void getAccount(struct Account account[])
{
    printf("New Account Data (Account#:%05d)\n", account->num_account);
    printf("----------------------------------------\n");
    // printf("\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    account->type_account = getCharOption("AC");

    printf("\n");
}

void getUserLogin(struct UserLogin *userlogging)
{
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");

    int nospace;

    do
    {
        printf("Enter user login (10 chars max): ");
        getCString(userlogging->name_login, 1, 10);

        // printf("\nname of login = %s\n", userlogging->name_login); ///////test

        nospace = whitespace(userlogging->name_login);

        // printf("\nname of login2 = %s\n", userlogging->name_login); ///////test

    } while (nospace == 1);

    printf("Enter the display name (30 chars max): ");
    getCString(userlogging->name_account, 1, 30);

    // printf("\name of account = %s\n", userlogging->name_account); ///////test

    // printf("\nname of login = %s\n", userlogging->name_login); ///////test

    int pass;

    do
    {
        printf("Enter the password (must be 8 chars in length): ");
        getCString(userlogging->password, 8, 8);

        pass = passwordsecurity(userlogging->password);

    } while (pass == 0);

    printf("\n");

    // printf("\nname of login = %s\n", userlogging->name_login); ///////test
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

    int k;

    for (k = 0; k < 30; k++)
    {
        demo->country[k] = toupper(demo->country[k]);
    }

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
            // printf("\n");
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
            int pass;

            do
            {
                printf("Enter the password (must be 8 chars in length): ");
                getCString(userlogging->password, 8, 8);

                pass = passwordsecurity(userlogging->password);

            } while (pass == 0);
            // printf("Enter the password (must be 8 chars in length): ");
            // getCString(userlogging->password, 8, 8);
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

            int k;

            for (k = 0; k < 30; k++)
            {
                demo->country[k] = toupper(demo->country[k]);
            }

            printf("\n");
            out = 0;
        }
        else if (selection == 0)
        {
            out = 1;
        }
    } while (out == 0);
}

int loadAccounts(struct Account accounts[], int maxSize_account)
{
    const char accountfilename[] = "accounts.txt";

    int i = 0;
    char ch = 'a';
    FILE *fp = fopen(accountfilename, "r");

    if (fp != NULL)
    {
        while (i < maxSize_account)
        {
            fscanf(fp, "%d~%c~%30[^~]~%[^~]~%8s~%d~%lf~%30[^\n]%c", &accounts[i].num_account, &accounts[i].type_account, accounts[i].logging.name_account, accounts[i].logging.name_login, accounts[i].logging.password, &accounts[i].demo.year_birth, &accounts[i].demo.income, accounts[i].demo.country, &ch);

            if (ch != '\n')
            {
                while (fgetc(fp) != '\n')
                    ;
            }

            while (accounts[i].num_account == 0)
            {
                // printf("\ni = %d\n", i);
                return i;
            }

            i++;
        }

        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("\nERROR: Unable to open file for reading.\n");
    }
    return i;
}

int archivingRemovedAccounts(struct Account *accounts, int maxSize_account, const char accountfilename[])
{
    // int i = 0;
    // FILE *fp1 = fopen(accountfilename, "r");

    // if (fp1 != NULL)
    // {
    //     for (i = 0; i < maxSize_account; i++)
    //     {
    //         ;
    //     }

    //     fclose(fp1);
    //     fp1 = NULL;
    // }

    // char ch = 'a';

    FILE *fp = fopen(accountfilename, "a");

    if (fp != NULL)
    {
        if (fprintf(fp, "%d~%c~%s~%s~%s~%d~%lf~%s", accounts->num_account, accounts->type_account, accounts->logging.name_account, accounts->logging.name_login, accounts->logging.password, accounts->demo.year_birth, accounts->demo.income, accounts->demo.country) != -1)
        {
            fprintf(fp, "\n");
            // i++;
        }

        // if (ch != '\n')
        // {
        //     while (fgetc(fp) != '\n')
        //         ;
        // }

        fclose(fp);
        fp = NULL;
    }
    // else
    // {
    //     printf("\nERROR.\n");
    // }
    return 0;
}

int totalArchivingAccounts(struct Account accounts[], int maxSize_account, const char accountfilename[])
{
    int i = 0;
    char ch = 'a';
    FILE *fp = fopen(accountfilename, "r");

    if (fp != NULL)
    {
        while (i < maxSize_account && fscanf(fp, "%d~%c~%30[^~]~%[^~]~%8s~%d~%lf~%30[^\n]%c", &accounts[i].num_account, &accounts[i].type_account, accounts[i].logging.name_account, accounts[i].logging.name_login, accounts[i].logging.password, &accounts[i].demo.year_birth, &accounts[i].demo.income, accounts[i].demo.country, &ch) == 9)
        {
            if (ch != '\n')
            {
                while (fgetc(fp) != '\n')
                    ;
            }
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    // else
    // {
    //     printf("\nERROR: Unable to archive accounts.\n");
    // }
    return i;
}

int saveaccounts(struct Account accounts[], int maxSize_account, const char accountfilename[])
{
    int i = 0;
    // char ch = 'a';
    FILE *fp = fopen(accountfilename, "w");

    if (fp != NULL)
    {

        while (i < maxSize_account)
        {
            if (accounts[i].num_account != 0)
            {
                fprintf(fp, "%d~%c~%s~%s~%s~%d~%lf~%s", accounts[i].num_account, accounts[i].type_account, accounts[i].logging.name_account, accounts[i].logging.name_login, accounts[i].logging.password, accounts[i].demo.year_birth, accounts[i].demo.income, accounts[i].demo.country);
                fprintf(fp, "\n");
            }

            // if (ch != '\n')
            // {
            //     while (fgetc(fp) != '\n')
            //         ;
            // }
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    return i;
}