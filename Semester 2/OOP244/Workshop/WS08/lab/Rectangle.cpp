///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Rectangle.h"
#include <cstring>
using namespace std;
namespace sdds {
	Rectangle::Rectangle() : LblShape()
	{
		m_height = 0;
		m_width = 0;
	}
	
	Rectangle::Rectangle(const char *cstr, int w, int h) : LblShape(cstr)
	{
		m_width = w;
		m_height = h;

		if (m_height < 3 && m_width < int(strlen(label())) + 2)
		{
			m_width = 0;
			m_height= 0;
		}
	}

	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(100, ',');
		istr >> m_height;
		istr.ignore(100, '\n');
	}

	void Rectangle::draw(std::ostream &ostr)const
	{
		if (m_width > 0 && m_height > 0 && label() != nullptr)
		{
			ostr << "+";
			for (int i = 0; i < m_width - 2; ++i) {ostr << '-';}
			ostr << "+" << "\n";
			
			ostr << "|";
			ostr.setf(ios::left);
			ostr.width(m_width - 2);
			ostr << label();
			ostr << "|" << "\n";
			
			for (int i = 0; i < m_height- 3; ++i)
			{
				ostr << "|";
				for (int i = 0; i < m_width - 2; ++i) {ostr << " ";}
				ostr << "|" << "\n";
			}

			ostr << "+";
			for (int i = 0; i < m_width - 2; ++i) {ostr << '-';}
			ostr << "+";
		}
	}

}