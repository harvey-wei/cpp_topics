#include <iostream>
#include "Coordinate.h"
using namespace std;
/*
   Binary Ops overloading!!! such as a+b, cout << b, a[i]
   //Note left operand is the frist parameter
   //the right one is the second parameter!
   // the implicit parameter this pointer takes up the first position in parameter list!!
1. overloaded +sign(as member function and friend funcion)
2. overloaded << (output ops) (can only be friend function)
3. overloaded [](indexing ops) (better to be defined as member function)
*/

int main()
{
	/* Coordinate coor1(1,3); */
	/* cout << coor1.get_x() << "," << coor1.get_y() << endl; */
	/* /1* ++coor1; // prefix increment operator, coor1.operator++(coor1) *1/ */
	/* cout << (coor1++).get_x() << "," << (coor1++).get_y() << endl; */
	/* // expected output, 1, 4 */

	/* cout << (coor1).get_x() << "," << (coor1).get_y() << endl; */
	/* // expected output: 3, 5 */
	Coordinate coor1(1, 3);
	Coordinate coor2(2, 4);
	Coordinate coor3(0, 0);

    int a, b;
    cin >> a >> b;
    cout << "a + b " << a + b << endl;

	coor3 = coor1 + coor2;
	/* cout << coor3.get_x() << "," << coor3.get_y() << endl; */	
	/* cout << coor3 << endl;; // operator<<(ostream &output, Coordinate coor) */
	cout << coor3[0] << endl;
	cout << coor3[1] << endl;

    std::cout << "Call overloaded operator () " << coor1.call_parentheses(3) << std::endl;

	return 0;
}
