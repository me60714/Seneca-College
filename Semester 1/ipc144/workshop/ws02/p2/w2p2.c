
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double amount, servicefee;
	int balance, toonies, loonies, quarters, dimes, nickels, pennies;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);

	servicefee = amount * 100 * 0.05;
	printf("Service fee (5.0 percent): %.2lf\n", servicefee / 100.0 + 0.005);

	balance = amount * 100.0 - servicefee;
	printf("Balance to dispense: $%.2lf\n", balance / 100.0);
	printf("\n");

	toonies = balance / 200;
	balance %= 200;
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, balance / 100.0);

	loonies = balance / 100;
	balance %= 100;
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, balance / 100.0);

	quarters = balance / 25;
	balance %= 25;
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, balance / 100.0);

	dimes = balance / 10;
	balance %= 10;
	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes, balance / 100.0);

	nickels = balance / 5;
	balance %= 5;
	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickels, balance / 100.0);

	pennies = balance / 1;
	balance %= 1;
	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", pennies, balance / 100.0);

	printf("\n");
	printf("All coins dispensed!\n");

	return 0;
}
