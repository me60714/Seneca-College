///////////////////////////////////////
//    Name   : Wei-Chih Kao          //
//    Email  : wkao3@myseneca.ca     //
//    ID     : 158000190             //
//    Date   : 2021.07.19            //
///////////////////////////////////////

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Shape.h"
using namespace std;
namespace sdds {
	Shape::~Shape(){;}

	ostream &operator<<(ostream &ostr, const Shape &shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	istream &operator>>(istream &istr, Shape &shape){
		shape.getSpecs(istr);
		return istr;
	}
}