// ===================================================================================
//  Assignment: 2
//  Milestone : 3
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"
#include "ticket.h"

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

//start
void applicationStartup(struct AccountTicketingData *data)
{

    int value, jump;
    char char_exit;

    do
    {
        value = menuLogin(data->accounts, data->ACCOUNT_MAX_SIZE);

        if (data->accounts[value].type_account == 'C')
        {
            menuCustomer(data, data->accounts[value]);
        }
        else if (data->accounts[value].type_account == 'A')
        {
            menuAgent(data, &data->accounts[value]);
        }

        if (value == -1)
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

//Menu Login
int menuLogin(const struct Account *account, int maxSize_account)
{

    int i, found, selection, jump = 0, value;
    // int num_account = 0;
    char userloginattempt[31], passwordattempt[9];

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
            for (i = 2; i >= 0 && jump == 0; i--)
            {
                printf("Enter the account#: ");
                found = findAccountIndexByAcctNum(0, account, maxSize_account, 1);

                printf("User Login    : ");
                getCString(userloginattempt, 1, 30);

                printf("Password      : ");
                getCString(passwordattempt, 1, 30);

                if (strcmp(account[found].logging.name_login, userloginattempt) == 0 && strcmp(account[found].logging.password, passwordattempt) == 0)
                {
                    puts("");
                    jump = 1;
                }
                else
                //  if (account[found].logging.name_login != userloginattempt || account[found].logging.password != passwordattempt)
                {
                    printf("INVALID user login/password combination! [attempts remaining:%d]\n\n", i);
                    jump = 0;
                }

                if (i <= 0)
                {
                    printf("ERROR:  Login failed!\n\n");
                    pauseExecution();
                }
            }
        }
        else if (selection == 0)
        {
            value = -1;
            jump = 1;
        }
    } while (jump != 1);

    if (value != -1)
        value = found;

    return value;
}

//Menu Agent
void menuAgent(struct AccountTicketingData *data, const struct Account *loggedingUser)
{

    int selection, found, num_account = 0, jump = 0, ticketaccount = 0;
    char change;

    do
    {
        printf("AGENT: %s (%d)\n", loggedingUser->logging.name_account, loggedingUser->num_account);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf(" 1) Add a new account\n");
        printf(" 2) Modify an existing account\n");
        printf(" 3) Remove an account\n");
        printf(" 4) List accounts: summary view\n");
        printf(" 5) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        puts(" 6) List new tickets");
        puts(" 7) List active tickets");
        puts(" 8) List closed tickets");
        puts(" 9) Manage a ticket");
        puts("10) Archive closed tickets");
        puts("----------------------------------------------");
        printf("0) Logout\n");
        printf("\nSelection: ");

        selection = getIntFromRange(0, 10);
        printf("\n");

        if (selection == 1)
        {
            int i;

            int emptyspace = -1;
            for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++)
            {
                if (data->accounts[i].num_account == 0)
                {
                    emptyspace = i;
                    //     nospace = 0;
                    //     break;
                    // }
                    // else if (data->accounts[i].num_account != 0)
                    // {
                    //     nospace = 1;
                }
            }

            if (emptyspace == -1)
            {
                printf("ERROR: Account listing is FULL, call ITS Support!\n\n");
                pauseExecution();
            }
            else if (emptyspace != -1)
            {
                int j, max = 0, mid = 0;

                for (j = 0; j < data->ACCOUNT_MAX_SIZE; j++)
                {
                    if (data->accounts[j].num_account > max)
                    {
                        mid = max;
                        max = data->accounts[j].num_account;
                    }
                    else if (data->accounts[j].num_account > mid)
                    {
                        mid = data->accounts[j].num_account;
                    }
                }

                data->accounts[emptyspace].num_account = max + 1;
                // printf("\nmax = %d\n", max);

                getAccount(&data->accounts[emptyspace]);
                getUserLogin(&data->accounts[emptyspace].logging);
                getDemographic(&data->accounts[emptyspace].demo);

                printf("*** New account added! ***\n\n");
                pauseExecution();
            }
        }
        else if (selection == 2)
        {
            printf("Enter the account#: ");
            found = findAccountIndexByAcctNum(num_account, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
            printf("\n");

            if (found == -1)
            {
                printf("\nERROR: Access Denied.\n\n");
                clearStandardInputBuffer();
                pauseExecution();
            }
            else if (found != -1)
            {
                updateAccount(&data->accounts[found]);
            }
        }
        else if (selection == 3)
        {
            printf("Enter the account#: ");
            found = findAccountIndexByAcctNum(num_account, data->accounts, data->ACCOUNT_MAX_SIZE, 1);

            if (found == -1)
            {
                printf("\nERROR: Access Denied.\n\n");
                clearStandardInputBuffer();
                pauseExecution();
            }
            else if (found != -1)
            {
                if (data->accounts[found].num_account == loggedingUser->num_account)
                {
                    printf("\nERROR: You can't remove your own account!\n\n");
                    clearStandardInputBuffer();
                    pauseExecution();
                }
                else if (data->accounts[found].num_account != loggedingUser->num_account)
                {
                    displayAllAccountDetailRecords(&data->accounts[found], 1);

                    printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
                    // clearStandardInputBuffer();
                    change = getCharOption("YN");

                    if (change == 'N')
                    {
                        printf("\n*** No changes made! ***\n");
                        printf("\n");
                        pauseExecution();
                    }
                    else if (change == 'Y') ///////remove
                    {
                        int k;
                        for (k = 0; k <= data->TICKET_MAX_SIZE; k++)
                        {
                            if (data->accounts[found].num_account == data->tickets[k].accountnum_customer)
                            {
                                // printf("\nfound = %d\n", data->accounts[found].num_account); ///////////test

                                ticketaccount = k;
                                if (data->tickets[ticketaccount].ticketstatus == 1 && data->tickets[ticketaccount].accountnum_customer == data->accounts[found].num_account)
                                {
                                    // memset(data->tickets[ticketaccount].messages, '\0', sizeof(data->tickets[ticketaccount].messages));
                                    // memset(data->tickets[ticketaccount].subjectline, '\0', sizeof(data->tickets[ticketaccount].subjectline));
                                    data->tickets[ticketaccount].accountnum_customer = 0;
                                    data->tickets[ticketaccount].counter = 0;
                                    *data->tickets[ticketaccount].messages->messagedetail = '\0';
                                    *data->tickets[ticketaccount].messages->name_account = '\0';
                                    data->tickets[ticketaccount].messages->type_account = '\0';
                                    *data->tickets[ticketaccount].subjectline = '\0';
                                    data->tickets[ticketaccount].num_ticket = 0;
                                    data->tickets[ticketaccount].ticketstatus = 0;
                                }
                                // else if (data->tickets[ticketaccount].ticketstatus != 1)
                                // {
                                //     printf("\nk = %d\n", ticketaccount);
                                //     printf("\naccount = %d\n", data->tickets[ticketaccount].accountnum_customer);
                                //     printf("\nticket number = %d\n", data->tickets[ticketaccount].num_ticket);
                                // }
                            }
                        }
                        // printf("\n%d\n", ticketaccount); //////////////////////////////////////////////////////////////////test
                        // printf("\nstatus = %d\n", data->tickets[ticketaccount].ticketstatus);
                        // printf("\ncounter = %d\n", data->tickets[ticketaccount].accountnum_customer);
                        // printf("\nmessage detail = %s\n", data->tickets[ticketaccount].messages->messagedetail);
                        // printf("\nname = %s\n", data->tickets[ticketaccount].messages->name_account);
                        // printf("\ntype = %c\n", data->tickets[ticketaccount].messages->type_account);
                        // printf("\nticket number = %d\n", data->tickets[ticketaccount].num_ticket);
                        // printf("\nsubject = %s\n", data->tickets[ticketaccount].subjectline);

                        // printf("\n%d\n", ticketaccount - 1); //////////////////////////////////////////////////////////////////test
                        // printf("\nstatus = %d\n", data->tickets[ticketaccount - 1].ticketstatus);
                        // printf("\ncounter = %d\n", data->tickets[ticketaccount - 1].accountnum_customer);
                        // printf("\nmessage detail = %s\n", data->tickets[ticketaccount - 1].messages->messagedetail);
                        // printf("\nname = %s\n", data->tickets[ticketaccount - 1].messages->name_account);
                        // printf("\ntype = %c\n", data->tickets[ticketaccount - 1].messages->type_account);
                        // printf("\nticket number = %d\n", data->tickets[ticketaccount - 1].num_ticket);
                        // printf("\nsubject = %s\n", data->tickets[ticketaccount - 1].subjectline);

                        data->accounts[found].num_account = 0;
                        data->accounts[found].type_account = '\0';
                        data->accounts[found].logging.name_account[0] = '\0';
                        data->accounts[found].logging.name_login[0] = '\0';
                        data->accounts[found].logging.password[0] = '\0';
                        data->accounts[found].demo.year_birth = 0;
                        data->accounts[found].demo.income = 0;
                        data->accounts[found].demo.country[0] = '\0';

                        printf("\n*** Account Removed! ***\n");
                        printf("\n");
                        pauseExecution();
                    }
                }
            }
        }
        else if (selection == 4)
        {
            displayAllAccountSummaryRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
            jump = 0;
            pauseExecution();
        }
        else if (selection == 5)
        {
            displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
            jump = 0;
            pauseExecution();
        }
        else if (selection == 6)
        {
            displayNewTicketDetail(data->tickets, data->TICKET_MAX_SIZE, data->accounts, data->ACCOUNT_MAX_SIZE, 1);
            jump = 0;
        }
        else if (selection == 7)
        {
            displayActiveTicketDetail(data->tickets, data->TICKET_MAX_SIZE, data->accounts, data->ACCOUNT_MAX_SIZE, 0);
            jump = 0;
        }
        else if (selection == 8) ///////////////////////List closed tickets
        {
            displayCloseTicketDetail(data->tickets, data->TICKET_MAX_SIZE, data->accounts, data->ACCOUNT_MAX_SIZE, 0);
            jump = 0;
        }
        else if (selection == 9) ////////////Manage a ticket
        {
            ticketManagement(data->tickets, data->TICKET_MAX_SIZE, data->accounts, data->ACCOUNT_MAX_SIZE, loggedingUser->num_account);
            jump = 0;
        }
        else if (selection == 10) ////////////Archive closed tickets
        {
            puts("Feature #10 currently unavailable!");
            puts("");
            pauseExecution();
            jump = 0;
        }
        else if (selection == 0)
        {
            printf("### LOGGED OUT ###\n\n");
            jump = 1;
        }
    } while (jump != 1);
}

//Menu Customer
void menuCustomer(struct AccountTicketingData *data, struct Account record)
{
    int selection, jump = 0, ticketFull, customeraccount;

    do
    {
        printf("CUSTOMER: %s (%d)\n", record.logging.name_account, record.num_account);
        puts("==============================================");
        puts("Customer Main Menu");
        puts("==============================================");
        puts("1) View your account detail");
        puts("2) Create a new ticket");
        puts("3) Modify an active ticket");
        puts("4) List my tickets");
        puts("----------------------------------------------");
        puts("0) Logout");
        puts("");
        printf("Selection: ");

        selection = getIntFromRange(0, 4);

        if (selection == 1)
        {
            puts("");
            displayAccountDetailHeader();
            displayAccountDetailRecord(&record);
            puts("");
            pauseExecution();
            jump = 0;
        }
        else if (selection == 2) ////create a new ticket
        {
            if (record.type_account == 'A')
            {
                printf("\n\nERROR :agents are not permitted to create tickets.\n\n");
            }

            ticketFull = displayNewTicketTitle(data->tickets, data->TICKET_MAX_SIZE);

            if (ticketFull != 0)
            {
                int i, stop = 0;

                for (i = 0; i < data->TICKET_MAX_SIZE && stop == 0; i++)
                {
                    if (data->tickets[i].num_ticket == ticketFull)
                    {
                        stop = 1; /////
                    }
                }

                data->tickets[i - 1].num_ticket = ticketFull;
                data->tickets[i - 1].accountnum_customer = record.num_account;
                data->tickets[i - 1].messages->type_account = record.type_account;
                strcpy(data->tickets[i - 1].messages->name_account, record.logging.name_account);
                data->tickets[i - 1].ticketstatus = 1;

                printf("Enter the ticket SUBJECT (30 chars. maximum): ");
                getCString(data->tickets[i - 1].subjectline, 1, 30);

                printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                getCString(data->tickets[i - 1].messages->messagedetail, 1, 150);
                data->tickets[i - 1].counter++;

                printf("\n*** New ticket created! ***\n\n");

                jump = 0;
                pauseExecution();
            }
            else if (ticketFull == 0)
                jump = 0;
        }
        else if (selection == 3) ////modify an active ticket
        {
            customeraccount = record.num_account;
            modifyticket(data->tickets, data->TICKET_MAX_SIZE, customeraccount, &record, data->ACCOUNT_MAX_SIZE);
            jump = 0;
        }
        else if (selection == 4)
        {
            puts("");
            displayCustomerTicketList(data->tickets, data->TICKET_MAX_SIZE, &record);
            jump = 0;
        }
        else if (selection == 0)
        {
            puts("");
            puts("### LOGGED OUT ###");
            puts("");
            jump = 1;
        }
    } while (jump != 1);
}

int findAccountIndexByAcctNum(int num_account, const struct Account account[], int maxSize_account, int promptornot)
{
    int value = 0;

    if (promptornot == 0)
    {
        int i, stop = 0;
        for (i = 0; (i < maxSize_account) && (stop == 0); i++)
        {
            // printf("num_account: %d account: %d\n", num_account, account[i].num_account);
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
    else
    {
        num_account = getInteger();

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

void displayListTicketHeader(void)
{
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
    printf("Ticket Acct# Display Name    Status Subject                        Messages\n");
    printf("------ ----- --------------- ------ ------------------------------ --------\n");
    return;
}

void displayNewTicketDetail(const struct Ticket *tickets, int size_Ticket, const struct Account *accounts, int size_account, int activeornew)
{
    int out = 0;
    while (tickets != NULL && out == 0)
    {
        int i = 0;
        int selection = -1;

        displayListTicketHeader();

        while (tickets[i].num_ticket != 0 && i < size_Ticket)
        {
            if (tickets[i].counter == 1)
                displayTicketDetail(&tickets[i], accounts, size_account);
            i++;
        }

        printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
        printf("Enter the ticket number to view the messages or\n");
        printf("0 to return to previous menu: ");

        selection = getPositiveInteger();
        int foundTicket = findTicketByNum(selection, tickets, size_Ticket);
        if (selection != 0 && foundTicket > -1)
        {
            printf("\n");
            displayMessageHeader(&tickets[foundTicket]);
            displayMessageContent(tickets[foundTicket].messages);
        }
        else if (selection != 0 && foundTicket == -1)
        {
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
        }
        else if (selection == 0)
        {
            printf("\n");
            out = 1;
        }
    }

    return;
}

void displayActiveTicketDetail(const struct Ticket *tickets, int size_Ticket, const struct Account *accounts, int size_account, int activeornew)
{
    int out = 0;
    while (tickets != NULL && out == 0)
    {
        int i = 0;
        int selection = -1;

        displayListTicketHeader();

        for (i = 0; i < size_Ticket; i++)
        {
            if (tickets[i].ticketstatus == 1 && tickets[i].num_ticket != 0)
                displayTicketDetail(&tickets[i], accounts, size_account);
        }

        printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
        printf("Enter the ticket number to view the messages or\n");
        printf("0 to return to previous menu: ");

        selection = getPositiveInteger();
        int foundTicket = findTicketByNum(selection, tickets, size_Ticket);

        if (selection != 0 && foundTicket > -1)
        {
            printf("\n");
            displayMessageHeader(&tickets[foundTicket]);
            displayMessageContent(tickets[foundTicket].messages);
        }
        else if (selection != 0 && foundTicket == -1)
        {
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
        }
        else if (selection == 0)
        {
            printf("\n");
            out = 1;
        }
    }

    return;
}

void displayCloseTicketDetail(const struct Ticket *tickets, int size_Ticket, const struct Account *accounts, int size_account, int activeornew)
{
    int out = 0;
    while (tickets != NULL && out == 0)
    {
        int i = 0;
        int selection = -1;

        displayListTicketHeader();

        for (i = 0; i < size_Ticket; i++)
        {
            if (tickets[i].ticketstatus == 0 && tickets[i].num_ticket != 0)
            {
                printf("%06d %05d %-15s %-6s %-30s %5d\n", tickets[i].num_ticket, tickets[i].accountnum_customer, tickets[i].messages->name_account, (tickets[i].ticketstatus == 1) ? "ACTIVE" : "CLOSED", tickets[i].subjectline, tickets[i].counter);
            }
        }

        printf("------ ----- --------------- ------ ------------------------------ --------\n\n");
        printf("Enter the ticket number to view the messages or\n");
        printf("0 to return to previous menu: ");

        selection = getPositiveInteger();
        int foundTicket = findTicketByNum(selection, tickets, size_Ticket);
        if (selection != 0 && foundTicket > -1)
        {
            printf("\n");
            displayMessageHeader(&tickets[foundTicket]);
            displayMessageContent(tickets[foundTicket].messages);
        }
        else if (selection != 0 && foundTicket == -1)
        {
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
        }
        else if (selection == 0)
        {
            printf("\n");
            out = 1;
        }
    }

    return;
}

void displayMessageHeader(const struct Ticket *tickets)
{
    printf("================================================================================\n");
    printf("%06d (%s) Re: %s", tickets->num_ticket, (tickets->ticketstatus == 1) ? "ACTIVE" : "CLOSED", tickets->subjectline);
    printf("\n");
    printf("================================================================================\n");
    return;
}

void displayMessageContent(const struct Message *messages)
{
    // printf("\ntest\nacc: %c | detail: %s\n\n", messages[1].type_account, messages[1].messagedetail);

    int i = 0, order = 0;
    while (messages != NULL && messages[i].type_account != 0 && i < NUM_MESSAGE_ARRAY)
    {
        printf("%s (%s):\n", messages[i].type_account == 'A' ? "AGENT" : "CUSTOMER", messages[i].name_account);
        printf("   %-s\n\n", messages[i].messagedetail);

        if ((i + 1) % 5 == 0)
        {
            pauseExecution();
        }
        order = i;
        i++;
    }

    // printf("\norder = %d\n", order);  test

    if ((order + 1) % 5 != 0)
        pauseExecution();
}

void displayTicketDetail(const struct Ticket *tickets, const struct Account *accounts, int size)
{
    int index = findAccountIndexByAcctNum(tickets->accountnum_customer, accounts, size, 0);
    if (index > -1)
    {
        printf("%06d %05d %-15s %-6s %-30s %5d\n", tickets->num_ticket, tickets->accountnum_customer, accounts[index].logging.name_account, (tickets->ticketstatus == 1) ? "ACTIVE" : "CLOSED", tickets->subjectline, tickets->counter);
    }
    // else if (index == -1)
    // {
    //     printf("\naaaaaa\n");
    // }
    return;
}

void displayCustomerTicketList(const struct Ticket *tickets, int size_Ticket, const struct Account *customer_account)
{
    int exit = 0;
    while (tickets != NULL && customer_account != NULL && exit == 0)
    {
        int i = 0;
        int selection = -1;

        displayCustomerTicketHeader();
        while (tickets[i].num_ticket != 0 && i < size_Ticket)
        {
            if (tickets[i].accountnum_customer == customer_account->num_account)
            {
                printf("%06d %-6s %-30s %5d\n", tickets[i].num_ticket, (tickets[i].ticketstatus == 1) ? "ACTIVE" : "CLOSED", tickets[i].subjectline, tickets[i].counter);
            }
            i++;
        }
        printf("------ ------ ------------------------------ --------\n\n");
        printf("Enter the ticket number to view the messages or\n");
        printf("0 to return to previous menu: ");

        selection = getPositiveInteger();
        int foundTicket = findTicketByNum(selection, tickets, size_Ticket);
        if (selection != 0 && foundTicket > -1 && tickets[foundTicket].accountnum_customer == customer_account->num_account)
        {
            printf("\n");
            displayMessageHeader(&tickets[foundTicket]);
            displayMessageContent(tickets[foundTicket].messages);
        }
        else if (selection != 0 && foundTicket > -1 && tickets[foundTicket].accountnum_customer != customer_account->num_account)
        {
            printf("\nERROR: Invalid ticket number - you may only access your own tickets.\n\n");
            pauseExecution();
        }
        else if (selection != 0 && foundTicket == -1)
        {
            printf("\nERROR: Invalid ticket number.\n\n");
            pauseExecution();
        }
        else if (selection == 0)
        {
            printf("\n");
            exit = 1;
        }
    }
    return;
}

int findTicketByNum(int num_ticket, const struct Ticket *tickets, int size_Ticket)
{
    int i = 0, found = 0, value = -1;
    while (tickets != NULL && 0 == found && i < size_Ticket)
    {
        if (tickets[i].num_ticket == num_ticket)
        {
            found = 1;
        }
        else
        {
            i++;
        }
    }
    value = (found == 1) ? i : -1;

    return value;
}

void displayCustomerTicketHeader(void)
{
    printf("------ ------ ------------------------------ --------\n");
    printf("Ticket Status Subject                        Messages\n");
    printf("------ ------ ------------------------------ --------\n");
    return;
}
