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

void displayAccountSummaryHeader(void)
{
    printf("Acct# Acct.Type Birth\n");
    printf("----- --------- -----\n");
}

void displayAccountDetailHeader(void)
{
    printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
    printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountSummaryRecord(const struct Account *account)
{
    if (account->type_account == 'A')
    {
        printf("%05d AGENT     %5d\n", account->num_account, account->demo.year_birth);
    }
    else if (account->type_account == 'C')
    {
        printf("%05d CUSTOMER  %5d\n", account->num_account, account->demo.year_birth);
    }
}

void displayAccountDetailRecord(const struct Account *account)
{
    char hiddenpassword[8] = {0};

    int i;
    for (i = 0; i < 8; i++)
    {
        if (i % 2 != 0)
        {
            hiddenpassword[i] = '*';
        }
        else
        {
            hiddenpassword[i] = account->logging.password[i];
        }
    }

    if (account->type_account == 'A')
    {
        printf("%05d AGENT     %5d $%10.2lf %-10s %-15s %-10s %c%c%c%c%c%c%c%c\n", account->num_account, account->demo.year_birth, account->demo.income, account->demo.country, account->logging.name_account, account->logging.name_login, hiddenpassword[0], hiddenpassword[1], hiddenpassword[2], hiddenpassword[3], hiddenpassword[4], hiddenpassword[5], hiddenpassword[6], hiddenpassword[7]);
    }
    else if (account->type_account == 'C')
    {
        printf("%05d CUSTOMER  %5d $%10.2lf %-10s %-15s %-10s %c%c%c%c%c%c%c%c\n", account->num_account, account->demo.year_birth, account->demo.income, account->demo.country, account->logging.name_account, account->logging.name_login, hiddenpassword[0], hiddenpassword[1], hiddenpassword[2], hiddenpassword[3], hiddenpassword[4], hiddenpassword[5], hiddenpassword[6], hiddenpassword[7]);
    }

    // if (account->type_account == 'A')
    // {
    //     printf("%05d AGENT     %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->num_account, account->demo.year_birth, account->demo.income, account->demo.country, account->logging.name_account, account->logging.name_login, hiddenpassword);
    // }
    // else if (account->type_account == 'C')
    // {
    //     printf("%05d CUSTOMER  %5d $%10.2lf %-10s %-15s %-10s %8s\n", account->num_account, account->demo.year_birth, account->demo.income, account->demo.country, account->logging.name_account, account->logging.name_login, hiddenpassword);
    // }
}

void applicationStartup(struct Account account[], int maxSize_account)
{
    int outornot, jump;
    char char_exit;

    do
    {
        outornot = menuLogin(account, maxSize_account);

        if (account[outornot].type_account == 'C')
        {
            printf("CUSTOMER: home menu currently unavailable...\n\n");
            clearStandardInputBuffer();
            pauseExecution();
        }
        else if (account[outornot].type_account == 'A')
        {
            menuAgent(account, maxSize_account, &account[outornot]);
        }

        if (outornot == -1)
        {
            printf("Are you sure you want to exit? ([Y]es|[N]o): ");
            char_exit = getCharOption("yYnN");

            if (char_exit == 'y' || char_exit == 'Y')
            {
                printf("\n==============================================\n");
                printf("Account Ticketing System - Terminated\n");
                printf("==============================================\n\n");

                jump = 1;
            }
            else if (char_exit == 'n' || char_exit == 'N')
            {
                printf("\n");
                jump = 0;
            }
        }
    } while (jump != 1);
}

int menuLogin(const struct Account account[], int maxSize_account)
{

    int selection, found, num_account = 0, jump;

    do
    {
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n\n");
        printf("Selection: ");

        selection = getIntFromRange(0, 1);
        printf("\n");

        if (selection == 1)
        {
            printf("Enter your account#: ");
            found = findAccountIndexByAcctNum(num_account, account, maxSize_account, 1);
            printf("\n");

            if (found == -1)
            {
                printf("ERROR:  Access Denied.\n\n");
                clearStandardInputBuffer();
                pauseExecution();
            }
            else if (found != -1)
            {
                jump = 1;
            }
        }
        else if (selection == 0)
        {
            found = -1;
            jump = 1;
        }
    } while (jump != 1);

    return found;
}

void menuAgent(struct Account account[], int maxSize_account, const struct Account *loggedingUser)
{

    int selection, nospace, emptyspace, found, num_account = 0, jump;
    char change;

    do
    {
        printf("AGENT: %s (%d)\n", loggedingUser->logging.name_account, loggedingUser->num_account);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: summary view\n");
        printf("5) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n");
        printf("\nSelection: ");

        selection = getIntFromRange(0, 5);
        printf("\n");

        if (selection == 1)
        {
            int i;

            for (i = 0; i < maxSize_account; i++)
            {
                if (account[i].num_account == 0)
                {
                    emptyspace = i;
                    nospace = 0;
                }
                else if (account[i].num_account != 0)
                {
                    nospace = 1;
                }
            }

            if (nospace == 1)
            {
                printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
                clearStandardInputBuffer();
                pauseExecution();
            }
            else if (nospace == 0)
            {
                getAccount(&account[emptyspace]);
                getUserLogin(&account[emptyspace].logging);
                getDemographic(&account[emptyspace].demo);

                printf("*** New account added! ***\n\n");
                pauseExecution();
            }
        }
        else if (selection == 2)
        {
            printf("Enter the account#: ");
            found = findAccountIndexByAcctNum(num_account, account, maxSize_account, 1);
            printf("\n");

            if (found == -1)
            {
                printf("\nERROR: Access Denied.\n\n");
                clearStandardInputBuffer();
                pauseExecution();
            }
            else if (found != -1)
            {
                updateAccount(&account[found]);
            }
        }
        else if (selection == 3)
        {
            printf("Enter the account#: ");
            found = findAccountIndexByAcctNum(num_account, account, maxSize_account, 1);

            if (found == -1)
            {
                printf("\nERROR: Access Denied.\n\n");
                clearStandardInputBuffer();
                pauseExecution();
            }
            else if (found != -1)
            {
                if (account[found].num_account == loggedingUser->num_account)
                {
                    printf("\nERROR: You can't remove your own account!\n\n");
                    clearStandardInputBuffer();
                    pauseExecution();
                }
                else if (account[found].num_account != loggedingUser->num_account)
                {
                    displayAllAccountDetailRecords(&account[found], 1);

                    printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
                    clearStandardInputBuffer();
                    change = getCharOption("YN");

                    if (change == 'N')
                    {
                        printf("\n*** No changes made! ***\n");
                        printf("\n");
                        pauseExecution();
                    }
                    else if (change == 'Y')
                    {
                        account[found].num_account = 0;
                        account[found].type_account = '\0';
                        account[found].logging.name_account[0] = '\0';
                        account[found].logging.name_login[0] = '\0';
                        account[found].logging.password[0] = '\0';
                        account[found].demo.year_birth = 0;
                        account[found].demo.income = 0;
                        account[found].demo.country[0] = '\0';

                        printf("\n*** Account Removed! ***\n");
                        printf("\n");
                        pauseExecution();
                    }
                }
            }
        }
        else if (selection == 4)
        {
            displayAllAccountSummaryRecords(account, maxSize_account);
            pauseExecution();
        }
        else if (selection == 5)
        {
            displayAllAccountDetailRecords(account, maxSize_account);
            pauseExecution();
        }
        else if (selection == 0)
        {
            printf("### LOGGED OUT ###\n\n");
            jump = 1;
        }
    } while (jump != 1);
}

int findAccountIndexByAcctNum(int num_account, const struct Account account[], int maxSize_account, int promptornot)
{
    int value;

    if (promptornot == 0)
    {
        int i, stop = 0;
        for (i = 0; (i < maxSize_account) && (stop == 0); i++)
        {
            if (num_account == account[i].num_account)
            {
                value = i;
                stop = 1;
            }
            else
            {
                value = -1;
                stop = 0;
            }
        }
    }
    else if (promptornot != 0)
    {
        scanf("%d", &num_account);

        int i, stop = 0;
        for (i = 0; (i < maxSize_account) && (stop == 0); i++)
        {
            if (num_account == account[i].num_account)
            {
                value = i;
                stop = 1;
            }
            else
            {
                value = -1;
                stop = 0;
            }
        }
    }
    return value;
}

void displayAllAccountSummaryRecords(const struct Account account[], int maxSize_account)
{
    displayAccountSummaryHeader();
    int i;
    for (i = 0; i < maxSize_account; i++)
    {
        displayAccountSummaryRecord(&account[i]);
    }
    printf("\n");
}

void displayAllAccountDetailRecords(const struct Account account[], int maxSize_account)
{
    displayAccountDetailHeader();
    int i;
    for (i = 0; i < maxSize_account; i++)
    {
        displayAccountDetailRecord(&account[i]);
    }
    printf("\n");
}

void pauseExecution(void)
{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');
}