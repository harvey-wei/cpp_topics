#include "Coordinate.h"
#include "iostream"
using namespace std;

Coordinate::Coordinate(int _coor_x, int _coor_y)
{
	m_int_coor_x = _coor_x;
	m_int_coor_y = _coor_y;
	cout << "Coordinate(int _coor_x, int _coor_y)" 
	<< " " << m_int_coor_x << "," << m_int_coor_y <<endl; 
}

Coordinate::~Coordinate()
{
	cout << "~Coordinate()" 
		<<" " << m_int_coor_x << "," << m_int_coor_y<< endl;
}

int Coordinate::get_coor_x()
{
	return m_int_coor_x;
}

int Coordinate::get_coor_y()
{
	return m_int_coor_y;
}

void Coordinate::set_coor_x(int _x)
{
	m_int_coor_x = _x;
}

void Coordinate::set_coor_y(int _y)
{
	m_int_coor_y = _y;
}
