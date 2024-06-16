#ifndef FLYING_H
#define FLYING_H
#include "Flying.h"


/* 
	Interface Class: Flying
	Member function: void takeoff(), void land() 
	No data member and other member functions except pure virutal function
	Interface Class is a special kind of abstract class with all member functions being pure virtual, even without constructor and destructor! This is where the name "interface class" comes from!!! There is no virtual function in interface class!!!
	Pure virtual function has no implementation while virtual function has implementation so as to achieve polymorphism!
	No implementations, hence no need to create the corresponding .cpp file
	No Constructor and No destructor
*/

/*

Q1: What is interface class? And how does the interface class relate to abstract class(ABC)?
C++ has no built-in concepts of interfaces. You can implement it using abstract classes which contains only pure virtual functions. Since it allows multiple inheritance, you can inherit this class to create another class which will then contain this interface (I mean, object interface :) ) in it.

In terms of the data member, Interface are nothing but a pure abstract class in C++. Ideally this interface class should contain only pure virtual public methods and static const data. Sometimes interface should not contain any data member. To summarize, interface only contain pure virtual function and not include constructor, destructor and any data member! This why interface class has no .cpp but only .h file!

Refer to the forum question at https://stackoverflow.com/questions/9756893/how-to-implement-interfaces-in-c/9756896

Q2: What is the use of the interface?
Interface Class is underpinned by ABC(Abstract Class) but lies at a higher level of abtraction!!! Hence, interface class is normally used to state a type of ability or protocol, more abstract than ABC. 

Like ABC(Abstract Class), Interface Class can not be used to create object neither but be inherited from!!!

One key summary: pure virtual function, abstract class(ABC), interface class corresponds to human cognitive process/psychology

Q3: What is the relation between Abstract Class(ABC) and interface class?
Interfaca Class Set is contained within the Abstract Class Set!!!
*/

// An example of interface class in C++ would be something like this:
//

// Flying means "able to fly"
class Flying_
{
	// Abstract class has neither constructor nor destructor.
	// ABC can not be used to instantiate but can be inherited.
	public:
		virtual	void takeoff() = 0;   // go off the land
		virtual void land() = 0;      // go down to the land
};

class Flying
{
	public:
		virtual void takeoff() = 0; // pure virtual function
		virtual void land() = 0;
};
#endif
