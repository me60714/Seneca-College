// ===================================================================================
//
//  Assignment:  1
//  Milestone:   3
//  Description: Main logic/tester
//
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    // *** NOTE: No other variables are allowed to be declared ***
    struct Account account = {0}; // *** DO NOT MODIFY THIS LINE ***

    printf("Assignment 1 Milestone 3 - Tester\n");             // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n"); // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data
    // ---------------------------------------------------------
    // Input (new record)
    //________________(__________________);   // Call function to get user input for a new "Account"
    getAccount(&account);

    // printf("account number = %d\n", account.num_account); ////////////////////////////////////////
    // printf("account type = %c\n", account.type_account);  /////////////////////////////////////////

    // ---------------------------------------------------------
    // UserLogin Data
    // ---------------------------------------------------------
    // Input (new record)
    //________________(__________________);   // Call function to get user input for a new "UserLogin"
    getUserLogin(&account.logging);

    // ---------------------------------------------------------
    // Demographic Data
    // ---------------------------------------------------------
    // Input (new record)
    //________________(__________________);  // Call function to get user input for a new "Demographic"
    getDemographic(&account.demo);

    // ---------------------------------------------------------
    // Display formatted Account summary/details
    // ---------------------------------------------------------
    //_______________________________;         // Call function to display the account SUMMARY header
    // ________________(__________________);   // Call function to display an account SUMMARY record
    displayAccountSummaryHeader();
    displayAccountSummaryRecord(&account);
    putchar('\n');

    //_______________________________;         // Call function to display the account DETAIL header
    // ________________(__________________);   // Call function to display an account DETAIL record
    displayAccountDetailHeader();
    displayAccountDetailRecord(&account);
    putchar('\n');
    printf("Account, User Login, and Demographic test completed!\n"); // *** DO NOT MODIFY THIS LINE ***

    return 0; // *** DO NOT MODIFY THIS LINE ***
}
