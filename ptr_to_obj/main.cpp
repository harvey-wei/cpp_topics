#include "main.h"
using namespace std;

int main()
{
	/* Coordinate *ptr_1 = new Coordinate(1,3); */
	/* Coordinate *ptr_2 = new Coordinate(4,5); */
	/* /1* int sum_x = ptr_1->m_int_x + ptr_2->m_int_x; *1/ */ 
	/* // Keep it in mind that data should be hidden(encapsulated) */
	/* // User can only access through the interface such get and set function !!! */
	/* int sum_x = ptr_1->get_x() + ptr_2->get_x(); // note that -> act on pointer!!! */
	/* int sum_y = ptr_1->get_y() + ptr_2->get_y(); */
	/* cout << "Sum of x Coordinates " << sum_x <<endl; */
	/* cout << "Sum of y Coordinates " << sum_y <<endl; */
	/* cout << "Sum of x Coordinates " << ptr_1->add_x(*ptr_2) <<endl; */
	/* cout << "Sum of y Coordinates " << ptr_1->add_y(*ptr_2) <<endl; */
	/* delete ptr_1; */
	/* ptr_1 = NULL; */
	/* delete ptr_2; */
	/* ptr_2 = NULL; */

	// instantiate the class from the stack 
	// and then create an pointer to the object!!
	Coordinate Coor_1;
	Coordinate *p = &Coor_1;   // & take the address
	// Remarks: view/treat/ object as regular object such as int, char, string, array!!!
	p->set_x(10);
	/* p->set_y(100); // */ 
	(*p).set_y(100);	
	cout << "x Coordinate " << Coor_1.get_x() << endl;
	cout << "y Coordinate " << Coor_1.get_y() << endl;
	return 0;
}
