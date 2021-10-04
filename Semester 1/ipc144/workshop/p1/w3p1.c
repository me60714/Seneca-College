/*
	==================================================
	Workshop #3 (Part-1):
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
int main() 
{
	const int JAN = 1;
	const int DEC = 12;
	int year, month;
	int valid; //flag here

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


	} while (!valid); //valid == 0;

	printf("\n*** Log date set! ***\n\n");
	switch (month)
	{
	case 1:
		printf("Log starting date: %d-JAN-01", year);
		break;
	case 2:
		printf("Log starting date: %d-FEB-01", year);
		break;
	case 3:
		printf("Log starting date: %d-MAR-01", year);
		break;
	case 4:
		printf("Log starting date: %d-APR-01", year);
		break;
	case 5:
		printf("Log starting date: %d-MAY-01", year);
		break;
	case 6:
		printf("Log starting date: %d-JUN-01", year);
		break;
	case 7:
		printf("Log starting date: %d-JUL-01", year);
		break;
	case 8:
		printf("Log starting date: %d-AUG-01", year);
		break;
	case 9:
		printf("Log starting date: %d-SEP-01", year);
		break;
	case 10:
		printf("Log starting date: %d-OCT-01", year);
		break;
	case 11:
		printf("Log starting date: %d-NOV-01", year);
		break;
	case 12:
		printf("Log starting date: %d-DEC-01", year);
		break;
	}

	return 0;
}