#include "iostream"
#include "string"
#include "coordinate.h"
using namespace std;

int main()
{
	Coordinate coor[3]; // instantiate class from the stack!!
	Coordinate *p = new Coordinate[3]; // instantiate class from the heap!!
	
	if(!p)
	{
		cout << "Allocation fails" <<endl;
	}
	// Unlike Matlab, C++ start counting from zero!!!!
	coor[0].set_coor_x(10);
	coor[0].set_coor_y(15);  

	p->set_coor_x(20); // access the first element of array 
	p[0].set_coor_y(30);

	(p+1)->set_coor_x(40);
	(p+1)->set_coor_y(50);
	// For the sake of simplicity, you can also use for-loop statement 
	// to assign the array of objects!!!!
	
	p++;   // p points to the second
	p++;   // p points to the last!
	p->set_coor_x(100);
	p->set_coor_y(200);
	
	// Traverse the array stored in the stack!!!
	for(int i = 0; i < 3; i++)
	{
		cout <<"coor_x"<< coor[i].get_coor_x() <<endl;
		cout <<"coor_y"<< coor[i].get_coor_y() <<endl;
	}

	// Traverse the array instantiated from the heap!!
	for(int i = 0; i < 3; i++)
	{
		// p points to the last element
		// Traverse frontwards
		//cout << "p_x" << (p-i)->get_coor_x() <<endl;
		//cout << "p_y" << (p-i)->get_coor_y() <<endl;
		cout << "p_x" << p->get_coor_x() <<endl;
		cout << "p_y" << p->get_coor_y() <<endl;
		p--;  // decrement and increment operator!!!!!
		// avoid  off-by-one error!!! 0,1,3
		// i = 2 , p-- occurs after cout!!!so no error!
	}
	p++ ;  // make p return to the memory allocated by new!!!!
	delete []p;  // So as not to forget to release the allocated memory!!
	// delete p only free up the first element of array
	/* delete p; */
	p = NULL;    // NULL is evaluated to 0; avoid reuse of released memory!!
	return 0;
}
