// ===================================================================================
//  Assignment: 2
//  Milestone : 1
// ===================================================================================
//  Student Name  : Wei-Chih kao
//  Student ID    : 158000190
//  Student Email : wkao3@myseneca.ca
//  Course Section: ZAA
// ===================================================================================

#ifndef TICKET_H_
#define TICKET_H_

struct Message
{
    char type_account;
    char name_account[31];
    char messagedetail[151];
};

struct Ticket
{
    int num_ticket;
    int accountnum_customer;
    int ticketstatus;
    char subjectline[31];
    int counter;
    struct Message messages[20];
};

#endif