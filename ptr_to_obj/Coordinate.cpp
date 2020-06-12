#include "iostream"
#include "Coordinate.h"
using namespace std;
Coordinate::Coordinate(int _x,int _y)
{
	m_int_x = _x;
	m_int_y = _y;
	cout << "Coordinate()" <<endl;
}
Coordinate::~Coordinate()
{
	cout << "~Coordinate" << "x Coordinate " << m_int_x <<endl;
}
void Coordinate::set_x(int _x)
{
	m_int_x = _x;
}
void Coordinate::set_y(int _y)
{
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
int Coordinate::add_x(Coordinate coor)
{
	return m_int_x + coor.m_int_x;  // coor will be created when being called!!!
}
int Coordinate::add_y(Coordinate coor)
{
	return m_int_y + coor.m_int_y; // coor will be created when being called!!!	
}
// After return value, coor will be destroyed via destructor!!!!
