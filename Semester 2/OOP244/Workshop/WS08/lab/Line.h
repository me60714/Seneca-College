///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"

using namespace std;
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char *cstr, int l);
		void getSpecs(istream &istr);
		void draw(ostream &ostr) const;
	};
}
#endif
