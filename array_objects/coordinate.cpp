#include "coordinate.h"
#include "iostream"
using namespace std;
// Stick to the strategy of separating declaration and implementation
// into different files,i.e. source file and header file!!!
Coordinate::Coordinate(int _x, int _y)
{
	m_int_x = _x;
	m_int_y = _y;
	cout << "Coordinate(int _x, int _y)" << endl;

}

Coordinate::~Coordinate()
{
	cout << "~Coordinate()" << endl;
}


void Coordinate::set_coor_x(int _x)
{
	m_int_x = _x;
}
void Coordinate::set_coor_y(int _y)
{
	m_int_y = _y;
}
int Coordinate::get_coor_x()
{
	return m_int_x;
}
int Coordinate::get_coor_y()
{
	return m_int_y;
}
