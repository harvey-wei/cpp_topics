#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape 
{
	protected:
		int m_int_radius;
	
	public:
		Circle(int _r);
		~Circle();

};
#endif
