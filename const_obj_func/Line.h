#ifndef LINE_H
#define LINE_H
#include "Coordinate.h" // Note that it must be included!!
class Line
{
	public:
		Line(int _Ax, int _Ay, int _Bx, int _By);
		~Line();
		void set_A(int _x, int _y);
		void set_B(int _x, int _y);
		void print_info();
		void print_info() const;  // In essence, const is prefixed to this pointer such that const member function can not modify the data members of the object!!!
	private:
		/* const Coordinate m_coor_A;  // instance of class Coordinate as the data member in another Class, especially for "object containing objects!!!!" */
		Coordinate m_coor_A;
		Coordinate m_coor_B;  // Note that here creation of Coordinate must comply with the corresponding constructor!!! constructor with default values may be a workaround!!
};
#endif
