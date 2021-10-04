// ===================================================================================
//
//  Assignment:  2
//  Milestone:   3
//  Description: Main
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |
// +---------------------------------------------------------+
//
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "accountTicketingUI.h"

// -----------------------------------------------------------------------------------
// System Data Array sizes
// -----------------------------------------------------------------------------------
#define ACCOUNT_SIZE 6
#define TICKET_SIZE 9

// -----------------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------------
void populateAccounts(struct Account accounts[], int arrSize);
void populateTickets(struct Ticket tickets[], int arrSize);

// -----------------------------------------------------------------------------------
// Main: Entry-point to the application
// -----------------------------------------------------------------------------------
int main(void)
{
    //----------------------------------------------
    // Variables
    //----------------------------------------------
    struct Account accounts[ACCOUNT_SIZE] = {{0}};
    struct Ticket tickets[TICKET_SIZE] = {{0}};
    struct AccountTicketingData data = {accounts, ACCOUNT_SIZE, tickets, TICKET_SIZE};

    //----------------------------------------------
    // Populate the data arrays...
    //----------------------------------------------

    // setup some test accounts:
    populateAccounts(data.accounts, data.ACCOUNT_MAX_SIZE);

    // setup some test tickets:
    populateTickets(data.tickets, data.TICKET_MAX_SIZE);

    //----------------------------------------------
    // launch application logic
    //----------------------------------------------
    applicationStartup(&data);

    return 0;
}

// -----------------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------------

void populateAccounts(struct Account accounts[], int arrSize)
{
    int i, max = arrSize < 5 ? arrSize : 5;
    struct Account tmp[5] = {
        {30001, 'C', {"Silly Sally", "cust1", "Aa1!3#Dd"}, {1990, 150000.10, "CANADA"}},
        {50599, 'A', {"Fred Flintstone", "agent1", "yAb1#a@B"}, {1972, 2250400.22, "AFRICA"}},
        {30004, 'C', {"Betty Boop", "cust2", "77*&FFaa"}, {1978, 250800.74, "INDIA"}},
        {50008, 'A', {"Will Smith", "agentJ", "TT*&21tt"}, {1952, 2350600.82, "U.S.A."}},
        {20020, 'C', {"Shrimpy Shrimp", "cust3", "8*3#JamC"}, {2000, 350500.35, "KOREA"}}};

    // Copy test records
    for (i = 0; i < max; i++)
    {
        accounts[i] = tmp[i];
    }
}

void populateTickets(struct Ticket tickets[], int arrSize)
{
    int i, max = arrSize < 8 ? arrSize : 8;
    struct Ticket tmp[8] = {
        // Ticket Test Record 1
        {80599, 20020, 1, "No power/does not turn on", 1,
         // Ticket messages:
         {{'C', "Shrimpy Shrimp", "The unit won't turn on - please help."}}},
        // Ticket Test Record 2
        {60001, 30004, 1, "Frequent Disconnects", 5,
         // Ticket messages:
         {{'C', "Betty Boop", "Every time I go near the microwave the unit disconnects."}, {'A', "Will Smith", "Don't go near the microwave."}, {'A', "Will Smith", "It will radiate waves which will interrupt the unit."}, {'C', "Betty Boop", "But I use the microwave a lot."}, {'A', "Will Smith", "You cook too much!"}}},
        // Ticket Test Record 3
        {64611, 20020, 0, "It gets hot and smokes", 4,
         // Ticket messages:
         {
             {'C', "Shrimpy Shrimp", "When I put it in the oven, it gets hot and starts smoking."},
             {'A', "Will Smith", "It is not designed to be put in the oven - your warranty is now void."},
             {'C', "Shrimpy Shrimp", "So you won't fix it?"},
             {'A', "Will Smith", "No - you will have to purchase another."},
         }},
        // Ticket Test Record 4
        {30530, 30004, 1, "Does not respond to command...", 20,
         // Ticket messages:
         {{'C', "Betty Boop", "Installation went fine, but it doesn't respond to my commands."}, {'A', "Fred Flintstone", "What commands in particular?"}, {'C', "Betty Boop", "It does not like it when I tell it to jump off a bridge."}, {'A', "Fred Flintstone", "Why would you ask it do that? Robots are sensitive too, and won't self destruct."}, {'C', "Betty Boop", "I told it I would repair it, and besides, it is supposed to do what I command."}, {'A', "Fred Flintstone", "It has limits - and will not cause harm to others or itself."}, {'C', "Betty Boop", "But the instructions don't mention that."}, {'A', "Fred Flintstone", "Did you read page 48?"}, {'C', "Betty Boop", "No, I could only read up to page 25."}, {'A', "Fred Flintstone", "Why can't you read beyond page 25?"}, {'C', "Betty Boop", "The robot hid the instructions."}, {'A', "Fred Flintstone", "Wait... you didn't read about robot retaliation?"}, {'C', "Betty Boop", "What does it say about retaliation?"}, {'A', "Fred Flintstone", "When a robot is not respected, it will discover ways to get back at you."}, {'C', "Betty Boop", "Now it has hidden my phone and car keys.  How do I fix this?"}, {'A', "Fred Flintstone", "The only way to fix your relationship is to appologize in a public place."}, {'A', "Fred Flintstone", "...and you must do it on your knee's using a sympathetic tone."}, {'C', "Betty Boop", "What if it doesn't believe me?"}, {'A', "Fred Flintstone", "You do NOT want to know the answer to that :("}, {'A', "Fred Flintstone", "Hello?"}}},
        // Ticket Test Record 5
        {80004, 20020, 1, "My head hurts!", 3,
         // Ticket messages:
         {{'C', "Shrimpy Shrimp", "When the unit is placed on my head it hurts."}, {'A', "Will Smith", "Don't place it on your head."}, {'C', "Shrimpy Shrimp", "I don't understand - why not?"}}},
        // Ticket Test Record 6
        {70533, 30004, 1, "Nothing happens...", 20,
         // Ticket messages:
         {{'C', "Betty Boop", "Instructions state to 'say yes' to the prompts - but nothing happens."}, {'A', "Fred Flintstone", "Is this when setting up the unit for the first time?"}, {'C', "Betty Boop", "Yes - it asks me if I'm ready to start and I tell it 'yes' nothing happens."}, {'A', "Fred Flintstone", "Are you pressing the 'yes' button on the unit?"}, {'C', "Betty Boop", "No, instructions state to say yes - not press any buttons."}, {'A', "Will Smith", "'say' was meant to be interpretted as press the 'yes' button."}, {'C', "Betty Boop", "But the instructions don't mention any buttons."}, {'A', "Will Smith", "Agreed, it isn't very clear, but you must press the yes button."}, {'C', "Betty Boop", "There's no button in the instruction booklet."}, {'A', "Will Smith", "The button isn't in the instructions, it will be on the device."}, {'C', "Betty Boop", "Oh I get it that now makes sense."}, {'C', "Betty Boop", "Wait... I get further now, but it's stops after pressing the yes button."}, {'A', "Will Smith", "What is the problem now?"}, {'C', "Betty Boop", "The instructions state to 'say no' if I have health issues."}, {'A', "Will Smith", "Do you have health issues?"}, {'C', "Betty Boop", "No."}, {'A', "Will Smith", "Then what is the problem exactly?"}, {'C', "Betty Boop", "It doesn't do anything when I say No."}, {'A', "Will Smith", "Again, you don't 'say' no, you must press the no button."}, {'C', "Betty Boop", "Oh I get it now - thanks!"}}},
        // Ticket Test Record 7
        {80020, 30004, 1, "It's broken/does not work", 19,
         // Ticket messages:
         {{'C', "Betty Boop", "When I took it out of the box, it was in pieces."}, {'A', "Will Smith", "You have to assemble it - read the instructions."}, {'C', "Betty Boop", "What are instructions?"}, {'A', "Will Smith", "The paper document that look's like a book with words."}, {'C', "Betty Boop", "Oh - right, okay so it says to snap part-1 to part-2."}, {'C', "Betty Boop", "Hello? what should I do?"}, {'C', "Betty Boop", "Then it says to place part-3 on parts 1 and 2 then twist."}, {'C', "Betty Boop", "Please help... I don't know what this means."}, {'A', "Will Smith", "It's been 9 months, are you still unable to assemble it?"}, {'C', "Betty Boop", "Yes, I am stuck on instruction 2 the twist part."}, {'A', "Will Smith", "Place part-3 into the grooves of parts 1 and 2, then rotate clockwise."}, {'C', "Betty Boop", "Why?"}, {'C', "Betty Boop", "Hello?"}, {'C', "Betty Boop", "Well I did what you said, now it's in 3 pieces again."}, {'A', "Will Smith", "What did you do?"}, {'C', "Betty Boop", "I put part-3 in the grooves, than I turned clockwise causing it to fall off the table."}, {'A', "Will Smith", "You were to rotate part-3 not turn yourself around!"}, {'C', "Betty Boop", "Well now what do I do?"}, {'A', "Will Smith", "What do you think?"}}},
        // Ticket Test Record 8
        {80204, 30001, 1, "It's very messy!", 2,
         // Ticket messages:
         {{'C', "Silly Sally", "It this supposed to be so messy?"}, {'A', "Will Smith", "It's a slime blaster - so yes, it is supposed to be VERY messy!"}}}};

    // Copy test records
    for (i = 0; i < max; i++)
    {
        tickets[i] = tmp[i];
    }
}
