#include <iostream>
#include <string>
#include <cstdlib>  // C library .h is needed if stdlib.h

//For a list of C standard C headers (stdio, stdlib, assert, ...), prepend a c and remove the .h. For example stdio.h becomes cstdio.
using namespace std;

/*
*  Class name: Movable
*  Pure Virtual Function: move
*  Hence the ABC
*/

class Movable
{
	public:
		virtual void move() = 0;
};

/*
   class name: Bus
   mode of inheritance: publicly from Movable
   Specific Member: carry
*/
class Bus : public Movable
{
	public:
		virtual void move()
		{
			cout << "Bus -- move" << endl;
		}

		void carry()
		{
			cout << "Bus -- carry" << endl;
		}
};

/*
	class name: Tank
	mode of inheritance: publicly form Movalbe
	Specific Methods: fire
*/
class Tank : public Movable
{
	public:
		virtual void move()
		{
			cout << "Tank -- move" << endl;
		}

		void fire()
		{
			cout << "Tank -- fire" << endl;
		}
};

/*
	Purpose: do something
	Functiona Name: do_something
	Inputs: Movable * ptr
	Outputs: void(empty)
	Key Ideas: respond differently to different input object type
	Thus, we need run-time type information/identification
*/
void do_something(Movable * ptr)
{
	ptr->move() ;  // virtual function achieves the run-time polymorphism!
	// ptr is a pointer of base class type to the derived class, hence ptr can access the derived version of the virtual function! Or ptr can be a pointer of the derived class!!!
	cout << "Type of Input"	<< typeid(ptr).name() <<endl;

	if(typeid(*ptr) == typeid(Bus))
	{
		// Pointer of base calss have no access to the derived part!!
		// Hence, the dynamic_cast<>()
		Bus * ptr_bus = dynamic_cast<Bus *>(ptr);
		ptr_bus -> carry();
	}
	
	if(typeid(*ptr) == typeid(Tank))
	{
		// Note that base class pointer to the derived class object can not access the derivided part
		// Thus,  dynamic_cast<destClass *>(ptr)
		Tank * ptr_tank = dynamic_cast<Tank *>(ptr);
		ptr_tank -> fire();
	}
}

int main()
{
	Bus b;
	Tank t;
	do_something(&b);
	do_something(&t);

	return 0;
}
