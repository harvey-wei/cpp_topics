#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/**
Class Name: Shoot
Pure Virtual Func: aim, reload
Hence the interface class! 
There nothing but pure virtual function in the class. Thus only header file is enough!
No constructor, No destructor, No virtual functions, No data members in Interface Class.
**/
// Function/Operator Overloading: same function name
// Function Hiding across inheritance hierachy: same function name
// Function Overriding(Virtual Function): Same Function Prototype(return type, function name, parameter list)
class Shoot 
{
	public:
		virtual void aim() = 0;
		virtual void reload() = 0; 
};

/*
Class Name: Gun
Mode of inheritance: publicly from Shoot
Member functions: concretized aim and reload!
*/
class Gun : public Shoot
{
	virtual void aim()
	{
		cout << "Gun -- aim" << endl;
	}
	
	virtual void reload()
	{
		cout << "Gun -- reload" << endl;
	}
};

/*
Global Function: Hunting
Input: Shoot s
Ouput: void
*/
void hunting(Shoot *s)
{
	s->aim();
	s->reload();
}

int main()
{
	Shoot *ptr = new Gun;
	if(!ptr)
	{
		cout << "Fail to allocate!" << endl;
	}

	hunting(ptr);
	
	delete ptr;
	ptr = nullptr;

	return 0;
}
