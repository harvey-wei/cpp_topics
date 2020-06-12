#include "iostream"
#include "Line.h"
using namespace std;
// how to initialize the data member!!
// data member is a pointer
// so you can use initializer list or regular inside init!!j
Line::Line(int x1, int y1, int x2, int y2)
{
	// You should make pointer point to memory!!!
	// Otherwise, the object to which the pointer points may be undefined!!!
	// This is why the pointer are combined with dynamical allocation of memory!!
	m_ptr_coor_A = new Coordinate(x1,y1);
	m_ptr_coor_B = new Coordinate(x2,y2);
	/* m_ptr_coor_A->set_x(x3); */
	/* m_ptr_coor_A->set_y(y1); */
	/* m_ptr_coor_B->set_x(x2); */
	/* m_ptr_coor_B->set_y(y2); */
	cout << "Line()" <<endl;
}
Line::~Line()
{
	cout << "~Line()" <<endl;
}
void Line::print_info()
{
	cout << "A is " << "(" << m_ptr_coor_A->get_x() << "," << m_ptr_coor_A->get_y() <<")" <<endl;	
	cout << "B is " << "(" << m_ptr_coor_B->get_x() << "," << m_ptr_coor_B->get_y() <<")" <<endl;	
}
