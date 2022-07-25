#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
using namespace std;

class Coordinate
{
	// Recall Friend keyword is not dictated by access qualifiers, public, private and protected
	friend Coordinate & operator-(Coordinate & coor);
	friend Coordinate operator+(const Coordinate &c1, const Coordinate &c2);
	friend ostream & operator<<(ostream &ouput, Coordinate &coor);
	// << is output operator. overloading it require that first parameter must be ostream & type, return type must be ostream &

	public:
		// Constructor
		Coordinate(int _x, int _y);
		Coordinate & operator++();   // unary operator, prefix ++
		Coordinate operator++(int); // int is a flag for suffix ++
		// For suffix ++(++a), the expression's value = old value!Hence, can not return a reference but a new object
		// operator function as an member function!!!
		/* Coordinate & operator-();    // minus unary operator */

		/* Coordinate operator+(const Coordinate & coor); // this pointer is the first parameter.!!!! */
		// overloaded indexing ops, better to be member function
		// this ptr is the first parameter
		int operator[](int ind);

        int operator()(int factor);
        int call_parentheses(int factor);

		int get_x();
		int get_y();

	private:
		int m_int_x;
		int m_int_y;
};
#endif
