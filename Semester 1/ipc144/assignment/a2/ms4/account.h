// ===================================================================================
//  Assignment: 2
//  Milestone : 4
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

struct Demographic
{
    int year_birth;
    double income;
    char country[100];
};

struct UserLogin
{
    char name_account[40];
    char name_login[31];
    char password[9];
};

struct Account
{
    int num_account;
    char type_account;
    struct UserLogin logging;
    struct Demographic demo;
};

void getAccount(struct Account account[]);

void getUserLogin(struct UserLogin *userlogging);

void getDemographic(struct Demographic *demo);

void updateAccount(struct Account *account);

void updateUserLogin(struct UserLogin *userlogging);

void updateDemographic(struct Demographic *demo);

int loadAccounts(struct Account accounts[], int maxSize_account);

int archivingRemovedAccounts(struct Account *accounts, int maxSize_account, const char accountfilename[]);

int totalArchivingAccounts(struct Account accounts[], int maxSize_account, const char accountfilename[]);

int saveaccounts(struct Account accounts[], int maxSize_account, const char accountfilename[]);

#endif