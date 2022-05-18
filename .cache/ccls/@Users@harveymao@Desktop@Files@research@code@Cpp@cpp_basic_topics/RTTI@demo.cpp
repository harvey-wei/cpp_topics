/*
Q1 What is typeid(object) and type_info?
Note typeid takes object not pointer to object!
typeid is a C++ language operator which returns type identification information at run time. It basically returns a type_info object, which is equality-comparable with other type_info objects.

typeid() is for classes where the dynamic type of a polymorphic object must be known and for static type identification.

Note, that the only defined property of the returned type_info object has is its being equality- and non-equality-comparable, i.e. type_info objects describing different types shall compare non-equal, while type_info objects describing the same type have to compare equal. Everything else is implementation-defined. Methods that return various "names" are not guaranteed to return anything human-readable, and even not guaranteed to return anything at a

Notes on the typeid(object) :
1. type_id returns a reference to the type_info pertaining to the type of the  object
2. typeid can only identify the type of object  and it is unable to find out the type of pointer
3. typeid(*ptr) where ptr is a pointer of base class to the drived class object return the type of derived class type only if the base class(and derived class) has virtual function! (This item is also required by dynamic_cast<> ()) 

common syntax: typeid(*obj_ptr).name() return the name of type
typeid(*obj_ptr) == typeid(class name) to determine whether they are of the same class type!
If same, classname *ptr_1 = dynamic_cast<class name*>(obj_ptr)

Q2: What is the dynamic_cast<type *>(ptr)?(paramters in both <> and () are pointer! )
dynamic_cast< Type* >(ptr) tries to take the pointer in ptr and safely cast it to a pointer of type Type*. But this cast is executed at runtime, not compile time. Because this is a run-time cast, it is useful especially when combined with polymorphic classes. In fact, in certian cases the classes must be polymorphic in order for the cast to be legal.(Class must have at least one virtual function!!!!)
Refer to the brief rundown on this topic at stack overflow address: https://stackoverflow.com/questions/2253168/dynamic-cast-and-static-cast-in-c.

In order for the virtual function to be active, you have to use the pointer of base class to points to the drived class object(also hold for reference!!!)

Member functio hiding works when using the pointer of derived classes to point to the object of the same drived class!

Notes on the use of dynamic_cast<type *>(ptr)
1. Both of the source and destination class type should have virtual function for the dynamic_cast to be successful!
2. dynamic_cast is able to be used for pointer and reference only!
3. it return the address of the destination class type, otherwise it return NULL(you can check first and then use!)

Q3: Why do we need RTTI?
Recall that pointer of base classes can only access the base part of the drived classes except the virtual function. Hence, the base part of the drived classes can be accessible after the pointer of base classes is cast into the pointer of derived classes!!

In real life, the base part of the derived classes may be the specific attributes to the drived class!
*/

#include <iostream>
#include "Flying.h"
#include "Bird.h"
#include "Plane.h"

using namespace std;
// typeid(object) can identify the class of the derived class object via pointer or reference of the base class
// typeid can also identify built-in type at run-time
// Hence, you can use typeid as the tool for type checking, similar to type() in Python!

/*
1.Both the source and destination class should have virtual functions!
2.dynamic_cast only take as source and destination the pointers or references. 
dynamic_cast<className *>(pointer)
dynamic_cast<className &>(reference)
*/
/*
C++ program to demonstrate the use of the Run-Time Type Information(Identification)
1. Flying: takeoff, land(all pure virtual), Interface class!
2. Plane: takeoff, land, carry
3. Bird: takeoff, land, foraging
4. Global Function: do_something(Flying *ptr)  // pointe of base class type
*/

void do_something(Flying * ptr)
{
	cout << typeid(*ptr).name() << endl;  // print  out the name of the class name
	ptr->takeoff();


	if(typeid(*ptr) == typeid(Bird))
	{
		// type casting at run time
		Bird * bird = dynamic_cast<Bird *>(ptr);  // convert ptr to Bird( base to derived convertion )
		bird->foraging();
	}

	if(typeid(*ptr) == typeid(Plane))
	{
		Plane * plane  = dynamic_cast<Plane *>(ptr);
		plane->carry();
	}

	ptr->land();
}

int main()
{
	// typeied can print out the type of the object instance
	double *k=0;
	cout << typeid(k).name() << endl;
	Plane b;  
	do_something(&b); // taking pointer of base class as the inputs!
	return 0;
}
