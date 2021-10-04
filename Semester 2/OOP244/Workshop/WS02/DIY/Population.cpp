///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.06.05            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstring>
#include <iostream>
#include "Population.h"
#include "File.h"

using namespace std;

namespace sdds
{
    int noOfPostal;
    PopulationOfCa *populationOfCa;

    bool load(PopulationOfCa &oneArea)
    {
        bool ok = false;
        char code[128];
        int amount;

        if (read(code) && read(amount))
        {
            int len = strlen(code) + 1;
            oneArea.postalCode = new char[len];

            strcpy(oneArea.postalCode, code);
            oneArea.population = amount;

            ok = true;
        }

        return ok;
    }

    bool load(const char filename[])
    {
        bool ok = false;
        int i = 0;

        if (openFile(filename))
        {
            noOfPostal = noOfRecords();
            populationOfCa = new PopulationOfCa[noOfPostal];

            for (i = 0; i < noOfPostal; i++)
            {
                load(populationOfCa[i]);
            }

            if (i != noOfPostal)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else
                ok = true;

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << filename << endl;
        }

        return ok;
    }

    void sort()
    {
        int i, j;
        PopulationOfCa temp;
        for (i = noOfPostal - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (populationOfCa[j].population > populationOfCa[j + 1].population)
                {
                    temp = populationOfCa[j];
                    populationOfCa[j] = populationOfCa[j + 1];
                    populationOfCa[j + 1] = temp;
                }
            }
        }
    }

    void display(const PopulationOfCa &oneArea)
    {
        cout << oneArea.postalCode << ":  " << oneArea.population << endl;
    }

    void display()
    {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < noOfPostal; i++)
        {
            cout << i + 1 << "- ";
            display(populationOfCa[i]);
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << addPopulation() << endl;
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfPostal; i++)
        {
            delete[] populationOfCa[i].postalCode;
        }

        delete[] populationOfCa;
    }

    int addPopulation()
    {
        int allPopulation = 0;

        for (int i = 0; i < noOfPostal; i++)
        {
            allPopulation += populationOfCa[i].population;
        }

        return allPopulation;
    }
}