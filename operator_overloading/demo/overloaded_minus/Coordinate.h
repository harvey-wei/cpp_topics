#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
using namespace std;

class Coordinate
{
	// Recall Friend keyword is not dictated by access qualifiers, public, private and protected
	friend Coordinate & operator-(Coordinate & coor);
	public:
		// Constructor
		Coordinate(int _x, int _y);

		// operator function as an member function!!!
		/* Coordinate & operator-();    // minus unary operator */

		int get_x();
		int get_y();
	
	private:
		int m_int_x;
		int m_int_y;
};
#endif
