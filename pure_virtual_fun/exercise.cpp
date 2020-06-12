#include <iostream>
#include <stdlib.h>  // For C library, .h is needed!
#include <string>
using namespace std;

/**
Class Name: Animal
Data Member: m_str_name
Virutal Function: move()
Pure Virtual Function: eat()
**/

class Animal
{
	protected:
		string m_str_name;
	
	public:
		// Default Constructor
		Animal() {}
		
		// Constuctor with parameters
		Animal(string _name)
		{
			m_str_name = _name;
			cout << "Animal" << endl;
		}

		// Virtual Destructor to avoid memory leakage when instantiating from the heap!
		virtual ~Animal()
		{
			cout << "~Animal" << endl;
		}

		//virtual function
		virtual void eat() 
		{
			cout << "Animal --" <<  m_str_name << "--eat" << endl;
		}

		// Pure virtual function
		virtual void move() =0;   // 
};

/**
Class Name: Dog
Mode of inheritance: pulicly inheriting from Animal
Member function: eat(), move()
**/

class Dog : public Animal
{
	public:
		// Constuctor without paramter
		Dog() {};

		// Constuctor with paramter
		Dog(string _name) : Animal(_name)
		{
			cout << "Dog" << endl;
		}

		// pure function with the same prototype as that in the base class
		virtual void eat() 
		{
			cout << "Dog--" << m_str_name << "--eat" << endl;
		}

		// concretize the pure virtual function move
		virtual void move()
		{
			cout << "Dog--" << m_str_name << "--move" << endl;
		}
};


int main()
{
	// Instantiating Dog from the heap using pointer of animal, which is the prerequisite of polymorphism achived by virutal function.
	
	Animal *ptr = new Dog("CPP");

	if(!ptr)
	{
		cout << "Allocation fails!" << endl;
	}

	ptr->eat();
	ptr->move();

	delete ptr;
	ptr = nullptr;

	return 0;
}
