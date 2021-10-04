///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Line.h"
using namespace std;
namespace sdds {

	Line::Line() : LblShape()
	{
		m_length = 0;
	}
	
	Line::Line(const char* cstr, int l) : LblShape(cstr)
	{
		m_length = l;
	}
	
	void Line::getSpecs(istream &istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(100,'\n');
	}

	void Line::draw(ostream &ostr) const
	{
		if(m_length > 0 && label() != nullptr)
		{
			ostr << label() << endl;
			for (int i = 0; i < m_length; ++i) {ostr << '=';}
		}
	}	
}