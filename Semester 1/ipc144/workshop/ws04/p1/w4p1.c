/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_ITEMS 1
#define MAX_ITEMS 10
int main() {
	const double MIN_INCOME = 500;
	const double MAX_INCOME = 400000;
	double income;
	int num_items;
	double cost[MAX_ITEMS];
	int priorty[MAX_ITEMS];
	char finance[MAX_ITEMS];
	double sum = 0;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do {
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		if (income < MIN_INCOME){
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (income > MAX_INCOME){
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
	} while (income < MIN_INCOME || income > MAX_INCOME);

	do {
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &num_items);

		if (num_items < MIN_ITEMS || num_items > MAX_ITEMS){
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}
	} while (num_items < MIN_ITEMS || num_items > MAX_ITEMS);

	int i;
	for (i = 0; i < num_items; i++){
		printf("\nItem-%d Details:\n", i + 1);

		do {
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] < 100){
				printf("      ERROR: Cost must be at least $100.00\n");
			}

		} while (cost[i] < 100);

		do {
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priorty[i]);
			if (priorty[i] < 1 || priorty[i] > 3){
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (priorty[i] < 1 || priorty[i] > 3);

		do{
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%*c%c", &finance[i]);

			if (finance[i] != 'y' && finance[i] != 'n'){
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}

		} while (finance[i] != 'y' && finance[i] != 'n');

		sum += cost[i];

	}

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	for (i = 0; i < num_items; i++){
		printf("%3d%7d%9c%15.2lf\n", i+1, priorty[i], finance[i], cost[i]);
	}

	printf("---- -------- -------- -----------\n");
	printf("%23c%11.2lf\n\n", '$', sum);
	printf("Best of luck in all your future endeavours!\n");

	return 0;
}