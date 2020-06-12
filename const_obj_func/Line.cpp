#include "Line.h"
#include "iostream"
using namespace std;
// Initializer should be put in the class define
Line::Line(int _Ax, int _Ay, int _Bx, int _By):m_coor_A(_Ax, _Ay),m_coor_B(_Bx,_By)
{
	cout << "Line()" << endl; // 
}
Line::~Line()
{
	cout << "~Line()" <<endl;

}
void Line::set_A(int _x, int _y)
{
	m_coor_A.set_coor_x(_x);
	m_coor_A.set_coor_y(_y);
}
void Line::set_B(int _x, int _y)
{
	m_coor_B.set_coor_x(_x);
	m_coor_B.set_coor_y(_y); // so set function is a must!!!
}
void Line::print_info()
{
	cout << "print_info" <<endl;
	cout << "("<< m_coor_A.get_coor_x() << ","<< m_coor_A.get_coor_y() <<")" << endl;
	cout << "("<< m_coor_B.get_coor_x() << ","<< m_coor_B.get_coor_y() <<")" << endl;
}
void Line::print_info() const
{
	cout << "print_info const" <<endl;
	/* cout << "("<< m_coor_A.get_coor_x() << ","<< m_coor_A.get_coor_y() <<")" << endl; */
	/* cout << "("<< m_coor_B.get_coor_x() << ","<< m_coor_B.get_coor_y() <<")" << endl; */
	// this function expect const object!!! so the above two lines must be deleted!!!
}
