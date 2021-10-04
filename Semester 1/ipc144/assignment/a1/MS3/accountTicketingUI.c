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
}