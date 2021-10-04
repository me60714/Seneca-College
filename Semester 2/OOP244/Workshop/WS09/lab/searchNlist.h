///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.28            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
#include "ReadWrite.h"
#include "Employee.h"
#include "Student.h"
#include "Car.h"

using namespace std;

namespace sdds {
	//First use the keywork template, and use the type name T and U to identify a type.
	template<typename T, typename U>
	//This search function can find if the key value is match in the array or not.
	//Also, it will add all the match found to the collection.
	bool search(Collection<T>& collection, T arr[], int size_arr, U key)
	{
		//set a boolean to control if the function is match or not.
		bool match = false;
		// a loop to go through all the elements of the array
		for (int i = 0; i < size_arr; i++)
		{
			//if the element in the array matchs the key value, 
			if(arr[i] == key)
			{
				//set the boolean to true means match, and add it to the collection.
				match = true;
				collection.add(arr[i]);
			}
		}
		return match;
	}

	//First use the keywork template, and use the type name T to identify a type.
	template<typename T>
	//This listArrayElements function will list all the elements of an array.
	void listArrayElements(const char* title_list, const T arr[], int size_arr)
	{
		//First print the tittle of the list of the array.
		cout << title_list << endl;
		//Use a loop to print the row number and also print the elements inside.
		for(int i = 0; i < size_arr; i++)
			cout << i+1 << ": " << arr[i] << endl;
	}
}

#endif