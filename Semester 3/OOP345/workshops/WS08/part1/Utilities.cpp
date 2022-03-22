// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name: Wei-Chih Kao
// Email: wkao3@myseneca.ca
// StudentID: 158000190
// Date: 2021. Nov. 18.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product* p = new Product(desc[i].desc, price[j].price);
					p->validate();  // validates the Product
					priceList += p; // adds it to its list
					delete p;
					p = nullptr;
				}
			}
		}
		return priceList;
	}
}