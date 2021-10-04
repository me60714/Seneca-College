/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
 
int main()
{
	const int JAN = 1;
	const int DEC = 12;
	int year, month;
	int valid;
	double morning, evening, sumMorning = 0, sumEvening = 0, avgMorning = 0, avgEvening = 0, avg, sum;

	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		valid = 1;
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		if (year<MIN_YEAR || year>MAX_YEAR)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			valid = 0;
		}
		if (month<JAN || month>DEC)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			valid = 0;
		}

	} while (!valid);

	printf("\n*** Log date set! ***\n");

	int i;
	for (i = 1; i <= LOG_DAYS; i++)
	{
		switch (month)
		{
		case 1:
			printf("\n%d-JAN-%02d\n", year, i);
			break;
		case 2:
			printf("\n%d-FEB-%02d\n", year, i);
			break;
		case 3:
			printf("\n%d-MAR-%02d\n", year, i);
			break;
		case 4:
			printf("\n%d-APR-%02d\n", year, i);
			break;
		case 5:
			printf("\n%d-MAY-%02d\n", year, i);
			break;
		case 6:
			printf("\n%d-JUN-%02d\n", year, i);
			break;
		case 7:
			printf("\n%d-JUL-%02d\n", year, i);
			break; 
		case 8:
			printf("\n%d-AUG-%02d\n", year, i);
			break;
		case 9: 
			printf("\n%d-SEP-%02d\n", year, i);
			break;
		case 10:
			printf("\n%d-OCT-%02d\n", year, i);
			break;
		case 11:
			printf("\n%d-NOV-%02d\n", year, i);
			break;
		case 12:
			printf("\n%d-DEC-%02d\n", year, i);
			break;
		}

		do
		{
			valid = 1;
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning);

			if (morning < 0.0 || morning > 5.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				valid = 0;
			}else
			{
				sumMorning += morning;
			}

		} while (!valid);

		do
		{
			valid = 1;
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &evening);

			if (evening < 0.0 || evening > 5.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				valid = 0;
			}else
			{
				sumEvening += evening;
			}

		} while (!valid);
	}

	sum = sumEvening + sumMorning;
	avgMorning = sumMorning / LOG_DAYS;
	avgEvening = sumEvening / LOG_DAYS;
	avg = (avgEvening + avgMorning) / 2;

	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", sumMorning);
	printf("Evening total rating: %.3lf\n", sumEvening);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n\n", sum);
	printf("Average morning rating:  %.1lf\n", avgMorning);
	printf("Average evening rating:  %.1lf\n", avgEvening);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf", avg);

	return 0;
}
