// ===================================================================================
//  Assignment: 2
//  Milestone : 3
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#ifndef TICKET_H_
#define TICKET_H_

#include "account.h"
#include "accountTicketingUI.h"

#define MAX_MESSAGE_LENGTH 150
#define NUM_MESSAGE_ARRAY 20

struct Message
{
    char type_account;
    char name_account[31];
    char messagedetail[MAX_MESSAGE_LENGTH + 1];
};

struct Ticket
{
    int num_ticket;
    int accountnum_customer;
    int ticketstatus;
    char subjectline[31];
    int counter;
    struct Message messages[NUM_MESSAGE_ARRAY];
};

void displayListTicketHeader(void);

void displayNewTicketDetail(const struct Ticket *tickets, int size_Ticket, const struct Account *accounts, int size_account, int activeornew);

void displayMessageHeader(const struct Ticket *tickets);

void displayMessageContent(const struct Message *messages);

void displayTicketDetail(const struct Ticket *tickets, const struct Account *accounts, int size);

int findTicketByNum(int num_ticket, const struct Ticket *tickets, int size_Ticket);

void displayCustomerTicketHeader(void);

void displayCustomerTicketList(const struct Ticket *tickets, int size_Ticket, const struct Account *customer_account);

int displayNewTicketTitle(struct Ticket *new_ticket, int maxsize_ticket);

void modifyticket(struct Ticket *tickets, int maxsize_ticket, int customeraccount, const struct Account *customer_account, int maxsize_account);

void displayCloseTicketDetail(const struct Ticket *tickets, int size_Ticket, const struct Account *accounts, int size_account, int activeornew);

void displayActiveTicketDetail(const struct Ticket *tickets, int size_Ticket, const struct Account *accounts, int size_account, int activeornew);

void ticketManagement(struct Ticket *tickets, int maxsize_ticket, const struct Account *customer_account, int maxsize_account, int num_agentaccount);

#endif