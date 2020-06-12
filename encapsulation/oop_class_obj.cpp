#include "iostream"
using namespace std;

// Abstraction of (x,y) in xoy Coordinate System into class Coordinate
class Coordinate
{
public:
	int x;
	int y;
	void print_x()
	{
		cout << x <<endl;
	}
	void print_y()
	{
		cout << y <<endl;
	}
}; // semicolon is necessary

int main()
{
	// instantiate the class from the stack(for non-static, local variable)
	Coordinate coor;
	coor.x = 10;    // dot for object !!!!
	coor.y = 20;
	coor.print_x();
	coor.print_y();

	// instantiate the class from heap (for dynamically allocated memory)
	Coordinate * p = new Coordinate(); // ()is good
	// check for p
	if (!p)  // equivalently, if(p == NULL), NULL has value 0. Hence, !p is true iff. p == NULL with value 0.
	{
		cout << "Allocation failure !!" <<endl; 
	}
	p->x = 100;   // -> for pointer to object !!!! whereas dot member operates on the object!
	p->y = 200;
	p->print_x();
	p->print_y();
	
	//Release 
	delete p;
	p = NULL;
	// Allocate, Check and Release for heap management!
}
