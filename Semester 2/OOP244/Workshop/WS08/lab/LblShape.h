///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
#include <iostream>

using namespace std;

namespace sdds {
	class LblShape : public Shape 
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char *cstr);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(istream &istr);
	};
}
#endif