// ===================================================================================
//  Assignment: 1
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

void displayAccountSummaryHeader(void);

void displayAccountDetailHeader(void);

void displayAccountSummaryRecord(const struct Account *account);

void displayAccountDetailRecord(const struct Account *account);

#endif