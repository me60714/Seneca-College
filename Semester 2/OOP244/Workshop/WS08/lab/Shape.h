///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>
using namespace std;

namespace sdds {
	class Shape {
	public:
		virtual void draw(ostream &ostr) const = 0;
		virtual void getSpecs(istream &istr) = 0;
		virtual ~Shape();
	};
	ostream &operator<<(ostream &ostr, const Shape &shape);
	istream &operator>>(istream &istr, Shape &shape);
}
#endif
