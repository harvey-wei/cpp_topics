#include <iostream>
#include "Coordinate.h"
using namespace std;

int main()
{
	Coordinate coor1(1,3);
	cout << coor1.get_x() << "," << coor1.get_y() << endl;
	/* ++coor1; // prefix increment operator, coor1.operator++(coor1) */
	
	cout << (coor1++).get_x() << "," << (coor1++).get_y() << endl;
	// expected output, 1, 4

	cout << (coor1).get_x() << "," << (coor1).get_y() << endl;
	// expected output: 3, 5
	return 0;
}
