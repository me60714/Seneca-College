/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Wei-Chih Kao
	ID     : 158000190
	Email  : wkao3@myseneca.ca
	Section: ZAA
*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCT 3
#define NUM_GRAMS 64
#define KGtoLBs 2.20462 //part2
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;
	double price;
	int calories;
	double weight;
};

struct ReportData //part2
{
	int sku;
	double price;
	int calories;
	double weight_lbs;
	double weight_kg;
	int weight_g;
	double total_serving;
	double cost_per_serving;
	double calories_per_serving;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *num);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int calories, const double *weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *weight_lbs, double *weight_kg);

// 9. convert lbs: g
int convertLbsG(const double *weight_lbs, int *weight_grams);

// 10. convert lbs: kg / g
void convertLbs(const double *weight_lbs, double *weight_kg, int *weight_grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gram_servingsize, const int weight_grams, double *num_serving);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price_product, const double *num_serving, double *cost_per_serving);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price_product, const double *total_cal, double *cost_per_cal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData, const int cheapestoption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start();