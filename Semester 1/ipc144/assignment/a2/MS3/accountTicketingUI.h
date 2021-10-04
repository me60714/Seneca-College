// ===================================================================================
//  Assignment: 2
//  Milestone : 3
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#ifndef ACCOUNTICKETINGUI_H_
#define ACCOUNTICKETINGUI_H_

#include "account.h"
#include "ticket.h"

struct AccountTicketingData
{
    struct Account *accounts;   // array of accounts
    const int ACCOUNT_MAX_SIZE; // maximum elements for account array
    struct Ticket *tickets;     // array of tickets
    const int TICKET_MAX_SIZE;  // maximum elements for ticket array
};

void displayAccountSummaryHeader(void);

void displayAccountDetailHeader(void);

void displayAccountSummaryRecord(const struct Account *account);

void displayAccountDetailRecord(const struct Account *account);

void applicationStartup(struct AccountTicketingData *data);

int menuLogin(const struct Account *account, int maxSize_account);

void menuAgent(struct AccountTicketingData *data, const struct Account *loggedingUser);

void menuCustomer(struct AccountTicketingData *data, struct Account record);

int findAccountIndexByAcctNum(int num_account, const struct Account account[], int maxSize_account, int promptornot);

void displayAllAccountSummaryRecords(const struct Account account[], int maxSize_account);

void displayAllAccountDetailRecords(const struct Account account[], int maxSize_account);

void pauseExecution(void);

#endif