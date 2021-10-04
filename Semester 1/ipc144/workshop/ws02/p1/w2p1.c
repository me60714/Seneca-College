
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double amount;
	int balance, toonies, loonies, quarters;
	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);

	balance = amount * 100;
	toonies = balance / 200;
	balance %= 200; //balance = balance % 200;
	printf("\n");
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, balance / 100.0); //(double)balance/100

	loonies = balance / 100;
	balance %= 100;
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, balance / 100.0);

	quarters = balance / 25;
	balance %= 25;
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, balance / 100.0);

	printf("\n");
	printf("Machine error! Thank you for letting me keep $%.2lf!\n", balance / 100.0);

	return 0;
}
