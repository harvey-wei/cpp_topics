#include "Coordinate.h"
#include <iostream>
using namespace std;

int main()
{
	Coordinate coor1(1, 4);
	cout << coor1.get_x() << "," << coor1.get_y() << endl;

	// Operator Overloading depends on the class type of the operand(s)!!!
	/* -(-coor1);   // coor1.operator-()  unary operator!!! */
	-coor1;
	cout << coor1.get_x() << "," << coor1.get_y() << endl;

	return 0;
}
