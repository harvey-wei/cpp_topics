#include "Coordinate.h"

Coordinate::Coordinate(int _x, int _y)
{
	m_int_x = _x;
	m_int_y = _y;
}

int Coordinate::get_x()
{
	return m_int_x;
}

int Coordinate::get_y()
{
	return m_int_y;
}
// Operator Function as a member function!!
// Returning an reference allows you chain this fucntion calls!!!
// -coor return an Coordinate
// -(-coor) is legal!!!!
/* Coordinate & Coordinate::operator-() */
/* { */
/* 	// reverse the sign of x and y */
/* 	// utilize the implicit this pointer to the current object */
/* 	m_int_x = - m_int_x;  // because this operator functio is member function.hence no need to use this pointer! */
/* 	this->m_int_y = - this->m_int_y; */

/* 	return *this;   // return the current object which is assigned to a reference! */
/* } */

Coordinate & operator-(Coordinate & coor)
{
	coor.m_int_x = -coor.m_int_x;
	coor.m_int_y = -coor.m_int_y;

	return coor;
}
