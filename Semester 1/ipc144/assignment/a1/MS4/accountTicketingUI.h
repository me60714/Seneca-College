// ===================================================================================
//  Assignment: 1
//  Milestone : 4
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#ifndef ACCOUNTICKETINGUI_H_
#define ACCOUNTICKETINGUI_H_

#include "account.h"

void displayAccountSummaryHeader(void);

void displayAccountDetailHeader(void);

void displayAccountSummaryRecord(const struct Account *account);

void displayAccountDetailRecord(const struct Account *account);

void applicationStartup(struct Account account[], int maxSize_account);

int menuLogin(const struct Account account[], int maxSize_account);

void menuAgent(struct Account account[], int maxSize_account, const struct Account *loggedingUser);

int findAccountIndexByAcctNum(int num_account, const struct Account account[], int maxSize_account, int promptornot);

void displayAllAccountSummaryRecords(const struct Account account[], int maxSize_account);

void displayAllAccountDetailRecords(const struct Account account[], int maxSize_account);

void pauseExecution(void);

#endif