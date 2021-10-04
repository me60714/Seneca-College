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
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ticket.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"

int displayNewTicketTitle(struct Ticket *new_ticket, int maxsize_ticket)
{
    int i, num_ticket, keepgoing = 1;
    for (i = 0; i < maxsize_ticket && keepgoing == 1; i++)
    {
        if (new_ticket[i].num_ticket == 0)
        {
            int j, max = 0, mid = 0;

            for (j = 0; j < maxsize_ticket; j++)
            {
                if (new_ticket[j].num_ticket > max)
                {
                    mid = max;
                    max = new_ticket[j].num_ticket;
                }
                else if (new_ticket[j].num_ticket > mid)
                {
                    mid = new_ticket[j].num_ticket;
                }
            }

            num_ticket = new_ticket[i].num_ticket = max + 1;

            printf("\nNew Ticket (Ticket#:%06d)\n", num_ticket);
            printf("----------------------------------------\n");

            keepgoing = 0;
        }
        else if (new_ticket[i].num_ticket != 0)
        {
            keepgoing = 1;
        }
    }

    if (keepgoing == 0)
        return num_ticket;
    else
    {
        printf("\nERROR: Ticket listing is FULL, call ITS Support!\n\n");
        pauseExecution();
        return 0;
    }
}

void modifyticket(struct Ticket *tickets, int maxsize_ticket, int customeraccount, const struct Account *customer_account, int maxsize_account)
{
    int mod_ticket, selection, m, accountorder;
    char newsubject;

    for (m = 0; m <= maxsize_account; m++)
    {
        if (customeraccount == customer_account[m].num_account)
            accountorder = m;
    }

    printf("\nEnter ticket number: ");
    mod_ticket = getInteger();

    int i, k, ticketplace, end = 0;
    for (k = 0; k <= maxsize_ticket; k++)
    {
        if (tickets[k].num_ticket == mod_ticket)
        {
            ticketplace = k;
        }
    }

    if (tickets[ticketplace].accountnum_customer != customeraccount)
    {
        printf("\nERROR: Invalid ticket number - you may only modify your own ticket.\n\n");
        pauseExecution();
    }
    else
    {
        for (i = 0; i <= maxsize_ticket && end == 0; i++)
        {
            if (mod_ticket == tickets[i].num_ticket && tickets[i].ticketstatus == 0)
            {
                printf("\nERROR: Ticket is closed - changes are not permitted.\n\n");
                pauseExecution();
            }
            else if (mod_ticket == tickets[i].num_ticket && tickets[i].ticketstatus == 1)
            {
                int jump = 0;

                do
                {
                    printf("\n----------------------------------------\n");
                    printf("Ticket %06d - Update Options\n", tickets[i].num_ticket);
                    printf("----------------------------------------\n");
                    printf("Status  : %s\n", (tickets[i].ticketstatus == 1) ? "ACTIVE" : "CLOSED");
                    printf("Subject : %s\n", tickets[i].subjectline);
                    printf("----------------------------------------\n");
                    printf("1) Modify the subject\n");
                    printf("2) Add a message\n");
                    printf("3) Close ticket\n");
                    printf("0) Done\n");
                    printf("Selection: ");
                    selection = getIntFromRange(0, 3);

                    if (selection == 1) ///////////////////Q1 if subject > 8, mod_ticket become garbled
                    {
                        printf("\nEnter the revised ticket SUBJECT (30 chars. maximum): ");
                        getCString(&newsubject, 1, 30);
                        strcpy(tickets[i].subjectline, &newsubject);
                    }
                    else if (selection == 2)
                    {
                        int j, stop = 0, count = 0;
                        for (j = 0; j <= NUM_MESSAGE_ARRAY && stop == 0; j++)
                        {
                            if (*tickets[i].messages[j].messagedetail != '\0')
                            {
                                count++;
                                if (count == NUM_MESSAGE_ARRAY)
                                {
                                    printf("\nERROR: Message limit has been reached, call ITS Support!\n");
                                    stop = 1;
                                }
                            }
                            else if (*tickets[i].messages[j].messagedetail == '\0')
                            {
                                printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                                getCString(tickets[i].messages[j].messagedetail, 1, 150);
                                tickets[i].counter++;
                                strcpy(tickets[i].messages[j].name_account, customer_account[accountorder].logging.name_account);
                                tickets[i].messages[j].type_account = customer_account[accountorder].type_account;

                                // printf("\ntest = %s\n", tickets[i].messages[j].name_account);
                                // printf("\ntest = %c\n", tickets[i].messages[j].type_account);
                                // printf("\ntest = %s\n", tickets[i].messages[j].messagedetail);
                                stop = 1;
                            }
                        }
                    }
                    else if (selection == 3)
                    {
                        char close, close_message;
                        printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                        close = getCharOption("yYnN");

                        if (close == 'Y' || close == 'y')
                        {
                            int l, stop = 0, count = 0;
                            for (l = 0; l <= NUM_MESSAGE_ARRAY && stop == 0; l++)
                            {
                                if (*tickets[i].messages[l].messagedetail != '\0') /////message array full
                                {
                                    count++;
                                    if (count == NUM_MESSAGE_ARRAY)
                                    {
                                        stop = 1;
                                        jump = 1;
                                        tickets[i].ticketstatus = 0;
                                        printf("\n*** Ticket closed! ***\n\n");
                                        pauseExecution();
                                    }
                                }
                                else if (*tickets[i].messages[l].messagedetail == '\0')
                                {
                                    printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
                                    close_message = getCharOption("yYnN");

                                    if (close_message == 'Y' || close_message == 'y')
                                    {
                                        printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                                        getCString(tickets[i].messages[l].messagedetail, 1, 150);
                                        tickets[i].counter++;

                                        strcpy(tickets[i].messages[l].name_account, customer_account[accountorder].logging.name_account);
                                        tickets[i].messages[l].type_account = customer_account[accountorder].type_account;

                                        stop = 1;
                                        jump = 1;
                                        tickets[i].ticketstatus = 0;
                                        printf("\n*** Ticket closed! ***\n\n");
                                        pauseExecution();
                                    }
                                    else
                                    {
                                        stop = 1;
                                        jump = 1;
                                        tickets[i].ticketstatus = 0;
                                        printf("\n*** Ticket closed! ***\n\n");
                                        pauseExecution();
                                    }
                                }
                            }
                        }
                    }
                    else if (selection == 0)
                    {
                        puts("");
                        pauseExecution();
                        jump = 1;
                    }
                } while (jump != 1);
            }
        }
    }
}

void ticketManagement(struct Ticket *tickets, int maxsize_ticket, const struct Account *account, int maxsize_account, int num_agentaccount)
{
    int inputticket = 0, ticketplace = 0, jump = 0, selection = -1, accountorder = 0, messagespace = -1, agentindex;

    printf("Enter ticket number: ");
    inputticket = getInteger();

    int i, j, k;
    for (i = 0; i <= maxsize_ticket; i++)
    {
        if (tickets[i].num_ticket == inputticket)
        {
            ticketplace = i;
        }
    }

    for (j = 0; j <= maxsize_account; j++)
    {
        if (account[j].num_account == tickets[ticketplace].accountnum_customer)
            accountorder = j;
    }

    for (k = 0; k <= maxsize_account; k++)
    {
        if (num_agentaccount == account[k].num_account)
            agentindex = k;
    }

    do
    {
        printf("\n----------------------------------------\n");
        printf("Ticket %06d - Update Options\n", inputticket);
        printf("----------------------------------------\n");
        printf("Status  : %s\n", (tickets[ticketplace].ticketstatus == 1) ? "ACTIVE" : "CLOSED");
        printf("Subject : %s\n", tickets[ticketplace].subjectline);
        printf("Acct#   : %d\n", tickets[ticketplace].accountnum_customer);
        printf("Customer: %s\n", account[accountorder].logging.name_account);
        printf("----------------------------------------\n");
        printf("1) Add a message\n");
        printf("2) Close ticket\n");
        printf("3) Re-open ticket\n");
        printf("0) Done\n");
        printf("Selection: ");
        selection = getIntFromRange(0, 3);

        if (selection == 1)
        {
            // int i;
            // for (i = 0; i <= NUM_MESSAGE_ARRAY; i++)
            // {
            // if (*tickets[ticketplace].messages[i].messagedetail != '\0')
            // {
            //     count++;
            //     if (count == NUM_MESSAGE_ARRAY)
            //     {
            //         messagefull = 1;
            //         stop = 1;
            //     }
            // }

            if (tickets[ticketplace].counter < NUM_MESSAGE_ARRAY)
            {
                messagespace = tickets[ticketplace].counter;
                // printf("\ntest\n messagespace = %d | counter = %d\n\n", messagespace, tickets[ticketplace].counter);
            }
            // }
            if (tickets[ticketplace].ticketstatus == 0)
            {
                printf("\nERROR: Ticket is closed - new messages are not permitted.\n");
                jump = 0;
            }
            else if (tickets[ticketplace].ticketstatus == 1 && messagespace == -1)
            {
                printf("\nERROR: Message limit has been reached, call ITS Support!\n");
                jump = 0;
            }
            else if (tickets[ticketplace].ticketstatus == 1 && messagespace != -1)
            {
                printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                getCString(tickets[ticketplace].messages[messagespace].messagedetail, 1, 150);
                strcpy(tickets[ticketplace].messages[messagespace].name_account, account[agentindex].logging.name_account);
                tickets[ticketplace].messages[messagespace].type_account = account[agentindex].type_account;
                tickets[ticketplace].counter++;

                // printf("\nmessage = %s\n", tickets[ticketplace].messages[messagespace].messagedetail);
                // printf("\nname = %s\n", tickets[ticketplace].messages[messagespace].name_account);
                // printf("\ntype =  %c\n", tickets[ticketplace].messages[messagespace].type_account);
                // printf("\nmessagespace = %d\n", messagespace);

                jump = 0;
            }
        }
        else if (selection == 2)
        {
            if (tickets[ticketplace].ticketstatus == 0)
            {
                printf("\nERROR: Ticket is already closed!\n");
                jump = 0;
            }
            else if (tickets[ticketplace].ticketstatus == 1)
            {
                printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                char closeticket;
                closeticket = getCharOption("YyNn");

                if (tickets[ticketplace].counter < NUM_MESSAGE_ARRAY)
                {
                    messagespace = tickets[ticketplace].counter;
                    // printf("\ntest\n messagespace = %d\n\n", messagespace);
                }

                if (messagespace == -1)
                {
                    if (closeticket == 'Y' || closeticket == 'y')
                    {
                        tickets[ticketplace].ticketstatus = 0;

                        // printf("\ntest\n messagespace = %d\n\n", messagespace); ///test

                        printf("\n*** Ticket closed! ***\n");
                        jump = 0;
                    }
                    else if (closeticket == 'N' || closeticket == 'n')
                    {
                        jump = 0;
                    }
                }
                else if (messagespace != -1)
                {
                    if (closeticket == 'Y' || closeticket == 'y')
                    {
                        printf("\nDo you want to leave a closing message? ([Y]es|[N]o): ");
                        char closemessage;
                        closemessage = getCharOption("YyNn");
                        if (closemessage == 'Y' || closemessage == 'y')
                        {
                            tickets[ticketplace].ticketstatus = 0;

                            printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                            getCString(tickets[ticketplace].messages[messagespace].messagedetail, 1, 150);
                            strcpy(tickets[ticketplace].messages[messagespace].name_account, account[agentindex].logging.name_account);
                            tickets[ticketplace].messages[messagespace].type_account = account[agentindex].type_account;
                            tickets[ticketplace].counter++;

                            printf("\n*** Ticket closed! ***\n");
                            jump = 0;
                        }
                        else if (closemessage == 'N' || closemessage == 'n')
                        {
                            tickets[ticketplace].ticketstatus = 0;
                            printf("\n*** Ticket closed! ***\n");
                            jump = 0;
                        }
                    }
                    else if (closeticket == 'N' || closeticket == 'n')
                    {
                        jump = 0;
                    }
                }
            }
        }
        else if (selection == 3)
        {
            if (tickets[ticketplace].ticketstatus == 1)
            {
                printf("\nERROR: Ticket is already active!\n");
                jump = 0;
            }
            else if (tickets[ticketplace].ticketstatus == 0)
            {
                printf("\nAre you sure you RE-OPEN this closed ticket? ([Y]es|[N]o): ");

                char option;
                option = getCharOption("YyNn");

                if (option == 'Y' || option == 'y')
                {
                    printf("\n*** Ticket re-opened! ***\n");
                    tickets[ticketplace].ticketstatus = 1;
                    jump = 0;
                }
                else if (option == 'N' || option == 'n')
                {
                    jump = 0;
                }
            }
        }
        else if (selection == 0)
        {
            printf("\n");
            jump = 1;
        }

    } while (jump != 1);
}