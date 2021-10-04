///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.12            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds
{
    class Food
    {
        char foodName[31];
        int calorie;
        int timeOfConsumption;
        void setName(const char *foodName);

    public:
        void display() const;
        void setEmpty();
        void set(const char *foodName, int calorieOfThisFood, int when);
        bool isValid() const;
        int foodCalorie() const;
        void when() const;
    };
}

#endif