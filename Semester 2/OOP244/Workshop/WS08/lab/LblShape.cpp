///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const {return m_label;}

	LblShape::LblShape()
	{
		if (m_label != nullptr)
			m_label = nullptr;
	}

	LblShape::LblShape(const char* cstr)
	{
		if (m_label != nullptr)
			delete [] m_label;

		m_label = new char[strlen(cstr) + 1];
		strcpy(m_label, cstr);
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream &istr){
		// char* temp = nullptr;
		// string str;
		// getline(istr, str.assign(temp), ',');

		// delete[] m_label;
		// m_label = new char[strlen(temp) + 1];
		// strcpy(m_label, temp);
		// istr.ignore(1000,',');

		char temp[100];
		istr.get(temp, 100, ',');

		delete[] m_label;
		m_label = new char[strlen(temp) + 1];
		strcpy(m_label, temp);
		istr.ignore(1000, ',');

		temp[0] = '\0';
	}
	
}