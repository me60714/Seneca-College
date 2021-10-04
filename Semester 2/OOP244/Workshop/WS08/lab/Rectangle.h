///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.20            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"

using namespace std;
namespace sdds {
	class Rectangle : public LblShape {
		int m_height = 0;
		int m_width = 0;
	public:
		Rectangle();
		Rectangle(const char* cstr, int w, int h);
		void getSpecs(istream &istr);
		void draw(ostream &ostr)const;
	};
}
#endif
