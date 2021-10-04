///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.05            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct PopulationOfCa{
        char* postalCode;
        int population;
    };

    bool load(PopulationOfCa &oneArea);
    bool load(const char filename[]);
    void sort();
    void display(const PopulationOfCa &oneArea);
    void display();
    void deallocateMemory();
    int addPopulation();
}
#endif // SDDS_POPULATION_H_