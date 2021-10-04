///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.12            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds
{
    void Food::setName(const char *name)
    {
        int lengthOfName = strLen(name);
        int endOfName = 0;

        if (lengthOfName < 31)
        {
            for (int i = 0; i < lengthOfName; i++)
            {
                foodName[i] = name[i];
                endOfName++;
            }
            foodName[endOfName] = '\0';
        }
        else
        {
            for (int i = 0; i < 31; i++)
            {
                foodName[i] = name[i];
            }
            foodName[30] = '\0';
        }
    }

    void Food::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(30);
            cout.fill('.');
            cout << foodName;
            cout << " | ";
            cout.setf(ios::right);
            cout.width(4);
            cout.fill(' ');
            cout << calorie;
            cout << " | ";
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(10);
            when();
            cout << " |" << endl;
            cout.unsetf(ios::right);
        }
        else
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
    }

    void Food::setEmpty()
    {
        calorie = 0;
        timeOfConsumption = 0;
    }
    void Food::set(const char *foodName, int calorieOfThisFood, int when)
    {
        if (calorieOfThisFood <= 0 || foodName == nullptr)
            setEmpty();
        else
        {
            setName(foodName);
            calorie = calorieOfThisFood;
            timeOfConsumption = when;

        }
    }

    bool Food::isValid() const
    {
        return(calorie > 0 && foodName[0] != '\0' && timeOfConsumption >= 1);
    }

    int Food::foodCalorie() const
    {
        return calorie;
    }

    void Food::when() const
    {
        switch (timeOfConsumption)
        {
        case (1):
            cout << "Breakfast";
            break;
        
        case (2):
            cout << "Lunch";
            break;

        case (3):
            cout << "Dinner";
            break;

        case (4):
            cout << "Snack";
            break;

        default:
            cout << "ERROR MEALTIME";
            break;
        }
    }
}