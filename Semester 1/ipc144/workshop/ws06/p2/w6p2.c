/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *num)
{
	int val;
	do
	{
		scanf("%d", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
		*num = val; // or num = &val
	return val;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *num)
{
	double val;
	do
	{
		scanf("%lf", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
		*num = val;
	return val;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num)
{
	struct CatFoodInfo food = {0};

	printf("\nCat Food Product #%d\n", sequence_num);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.sku);
	printf("PRICE         : $");
	getDoublePositive(&food.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);

	return food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories, const double *weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *weight_lbs, double *weight_kg)
{
	double val = 0.0;

	val = *weight_lbs / KGtoLBs;

	if (weight_kg != NULL)
	{
		*weight_kg = val;
	}

	return val;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *weight_lbs, int *weight_grams)
{
	double val = 0.0;
	double val2 = 0.0;
	int val3;

	val = *weight_lbs;
	val3 = convertLbsKg(&val, &val2) * 1000;

	if (weight_grams != NULL)
	{
		*weight_grams = val3;
	}

	return val3;
}

// 10. convert lbs: kg and g
void convertLbs(const double *weight_lbs, double *weight_kg, int *weight_grams)
{
	double val = 0.0;
	double val2 = 0.0;
	int val3;

	val = *weight_lbs;
	val2 = convertLbsKg(&val, &val2);
	val3 = convertLbsG(&val, &val3);

	*weight_kg = val2;
	*weight_grams = val3;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gram_servingsize, const int weight_grams, double *num_serving)
{
	//int val = 0;
	double val;

	//val = weight_grams;
	val = (double)weight_grams / gram_servingsize;

	if (num_serving != NULL)
	{
		*num_serving = val;
	}

	return val;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price_product, const double *num_serving, double *cost_per_serving)
{
	double val = 0.0;
	double val2 = 0.0;
	double val3;

	val = *price_product;
	val2 = *num_serving;
	val3 = val / val2;

	if (cost_per_serving != NULL)
	{
		*cost_per_serving = val3;
	}

	return val3;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price_product, const double *total_cal, double *cost_per_cal)
{
	double val = 0.0;
	double val2 = 0.0;
	double val3;

	val = *price_product;
	val2 = *total_cal;
	val3 = val / val2;

	if (cost_per_cal != NULL)
	{
		*cost_per_cal = val3;
	}

	return val3;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo food)
{
	int sku;
	int calories;
	int weight_g;
	double price;
	double weight_lbs;
	double weight_kg;
	double total_serving;
	double cost_per_serving;
	double calories_per_serving;
	double val = 0.0;
	int val2 = 0;
	double val3 = 0.0;
	double val4 = 0.0;
	double val5 = 0.0;

	sku = food.sku;
	price = food.price;
	calories = food.calories;
	weight_lbs = food.weight;
	weight_kg = convertLbsKg(&food.weight, &val);
	weight_g = convertLbsG(&food.weight, &val2);
	total_serving = calculateServings(NUM_GRAMS, weight_g, &val3);
	cost_per_serving = calculateCostPerServing(&food.price, &total_serving, &val4);

	double val6 = (double)food.calories * total_serving;

	calories_per_serving = calculateCostPerCal(&food.price, &val6, &val5);

	struct ReportData data = {sku, price, calories, weight_lbs, weight_kg, weight_g, total_serving, cost_per_serving, calories_per_serving};

	return data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	int val;
	val = NUM_GRAMS;

	printf("\nAnalysis Report (Note: Serving = %dg\n", val);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int cheapestoption)
{
	if (cheapestoption == 0)
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n",
			   data.sku, data.price, data.weight_lbs, data.weight_kg, data.weight_g, data.calories, data.total_serving, data.cost_per_serving, data.calories_per_serving);

	if (cheapestoption != 0)
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n",
			   data.sku, data.price, data.weight_lbs, data.weight_kg, data.weight_g, data.calories, data.total_serving, data.cost_per_serving, data.calories_per_serving);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo food)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", food.sku, food.price);
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo cats[MAX_PRODUCT] = {{0}};
	struct ReportData data[MAX_PRODUCT] = {{0}};
	int cheapestoption;

	openingMessage(MAX_PRODUCT);
	int i;
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
		data[i] = calculateReportData(cats[i]);
	}

	printf("\n");

	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayCatFoodData(cats[i].sku, &cats[i].price, cats[i].calories, &cats[i].weight);
	}

	int min_cost_per_serving = 999;
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		if (data[i].cost_per_serving < min_cost_per_serving)
		{
			cheapestoption = i;
			min_cost_per_serving = data[i].cost_per_serving;
		}
	}

	displayReportHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayReportData(data[i], i == cheapestoption);
	}

	displayFinalAnalysis(cats[cheapestoption]);
}
