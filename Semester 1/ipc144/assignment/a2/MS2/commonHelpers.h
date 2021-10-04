/*
	==================================================
	Assignment #2 Milestone #2
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

//1
int currentYear(void);

//2
void clearStandardInputBuffer(void);

//3
int getInteger(void);

//4
int getPositiveInteger(void);

//5
double getDouble(void);

//6
double getPositiveDouble(void);

//7
int getIntFromRange(int lower_bound, int upper_bound);

//8
char getCharOption(const char *l_validChart);

//9
void getCString(char *cstring, int minNum_chart, int maxNum_chart);

int passwordsecurity(char *string);

int whitespace(char *string);

#endif