#include "iostream"
#include "Coordinate.h"
using namespace std;

// default value can not occur in def!!!
// if def and declaration are separated!
Coordinate::Coordinate(int _x, int _y)
{
	m_i_x = _x;
	m_i_y = _y;
	cout << "Coordinate()" <<endl;
}
Coordinate::~Coordinate()
{
	cout << "~Coordinate()" <<endl;
}
void Coordinate::set_x(int _x)
{
	m_i_x = _x;	
}
void Coordinate::set_y(int _y)
{
	m_i_y = _y;
}
int Coordinate::get_x()
{
	return m_i_x;
}
int Coordinate::get_y()
{
	return m_i_y;
}
