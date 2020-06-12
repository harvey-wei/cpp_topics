#include "iostream"
#include "Coordinate.h"
#include "Line.h"
using namespace std;

int main()
{
const Line *p = new Line(1,2,3,4); // due to the constructor,() is needed/required/necessary
	
	/* Line *p = new Line; // is also OK!! */
	if(!p)
	{
		cout << "Allocation fails" <<endl;
	}
	p->print_info();  //() is used to call the function!!!!	
	delete p;
	p = NULL; // the location to which p points has been deallocated!!!
	// When being created, the object member will be created before superobject
	// When being freed, the superobject will destroyed before object member
}
