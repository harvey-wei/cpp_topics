#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
/*
Q1: What is the pure virtual function and abstract class?
Pure virutal function is one sort of virtual function without function body!Hence, the "pure" in the term. The class containing one or more pure virtual functions tered "Abstract Class". Like regular virtual function, the pure virtual function is abole to be inherited. Thus, the derived of the abstract class is also an abstract until all pure virtual function are concretized by adding the function body. Apparently, the abstract class and its child class can not be instantiated until all the pure virtual functions are concretly defined!

Q2: What is the working of pure virtual function?
As indicated above, the pure virtual function is one type of virtual function. Therefore, it also follow the pattern: VPTR per object instance -> VTABLE per class -> Virtual Function in the code segment except that the pointer to the pure virtual function in the VTABLE(a static array of pointers to virtual functions for one class)

Q3: Default values, initializer list can be placed in the definition!
However. the virtual keyword should be put in the declaration!!

Q4: Why we need pure virtual functon and abstract class?
According to the google dictionary, "abstract" is interpreted as existing in thought or as an idea but not having a physical or concrete existence not based on a particular instance.In other words, abstract ideas can be more concrete! In real life, there are "abstract concept" remaining to be concretized further!

Based on the above reasons, the abstract class plays a significant role in Object Oriented Programming!

Q5: How to declare a pure virtual function?
A pure virtual function (or abstract function) in C++ is a virtual function for which we don’t have implementation, we only declare it. A pure virtual function is declared by assigning 0 in declaration. See the following example.

virtual void print_info() = 0; // Assignng 0 in declartion declares a pure virtual function!

Q6: When to implement the pure virtual function?
A pure virtual function is implemented by classes which are derived from a Abstract class. Following is a simple example to demonstrate the same.

We can have pointers and references of abstract class type. That means the pointer of abstract class(base) can point to the derived class(non-abstract)
*/

class Person
{
	protected:
		string m_str_name;

	public:
		Person(string _name);
		virtual ~Person();
		// pure virtual function can also be inherited // the same
		virtual void work() = 0; // pure virtual function "=0" in place of body
};

// When keeping the declaration separate from the definition, virtual keyword only occur in the the declaration!!!
// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
#endif
