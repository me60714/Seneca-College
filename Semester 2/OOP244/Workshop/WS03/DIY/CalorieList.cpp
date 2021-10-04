///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.12            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds
{
    int CalorieList::totalcalories() const
    {
        double sum = 0.0;

        for (int i = 0; i < noOfFood; i++)
            sum += foodInfo[i].foodCalorie();
        
        return sum;
    }

    void CalorieList::title() const
    {
        cout << "+----------------------------------------------------+" << endl;

        if (isValid())
            cout << "|  Daily Calorie Consumption                         |" << endl;
        else
            cout << "| Invalid Calorie Consumption list                   |" << endl;

        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;

        if (isValid())
        {
            cout << "|    Total Calories for today:   ";
            cout.width(6);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << totalcalories();
            cout << " |            |" << endl;
        }
        else
            cout << "|    Invalid Calorie Consumption list                |" << endl;

        cout << "+----------------------------------------------------+" << endl;
    }
    
    void CalorieList::setEmpty()
    {
        foodInfo = nullptr;
    }
    
    bool CalorieList::isValid() const
    {
        bool b;
        if (foodInfo != NULL)
        {
            for (int i = 0; i < noOfFood; i++)
            {
               if (foodInfo[i].foodCalorie() <= 0)
               {
                   b = false;
                   break;
               }

               b = true;

            }
        }
        else
            b = false;
        
        return b;
    }
    
    void CalorieList::init(int size)
    {
        if (size <= 0)
            setEmpty();
        else
        {
            noOfFood = size;
            foodAdd = 0;

            foodInfo = new Food[noOfFood];
            for (int i = 0; i < noOfFood; i++)
                foodInfo[i].setEmpty();
        }
    }
    
    bool CalorieList::add(const char *foodName, int calories, int when)
    {
        if (foodAdd < noOfFood)
        {
            foodInfo[foodAdd].set(foodName, calories, when);
            foodAdd++;
            return true;
        }

        return false;
    }
    
    void CalorieList::display() const
    {
        title();

        for (int i = 0; i < noOfFood; i++)
            foodInfo[i].display();

        footer();
    }
    
    void CalorieList::deallocate()
    {
        delete[] foodInfo;
        foodInfo = nullptr;
    }
}