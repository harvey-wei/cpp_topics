#include <iostream>
#include <string>
using namespace std;
// Public mode of inheritance preserves/retains/maintains the access specifier except that the private members become inaccessible to the derived class. This feature of publicly inheriting makes it used more often than the other modes!!

class Shape 
{
	public:
		Shape()
		{
			cout << "Shape()" << endl;
		}

		~Shape()
		{
			cout << "~Shape()" <<endl;
		}

		double calc_area()
		{
			cout <<"Shape->calc_area()"<< endl;

			return 0;
		}
};

class Circle : public Shape 
{
	public:
		Circle(double _r)
		{
			cout << "Circle()" << endl;
			m_db_radius = _r;
		}

		~Circle()
		{
			cout << "~Circle()" <<endl;
		}


/*

In inheritance, functions with identical name(may be different in parameter list) can not be overloaded! Instead, the function in the subclass will hide the function with the same name. But you can also invoke the that in the superclass by the class name followed by the scope resolution operator!!!!
*/

		double calc_area()  // hide the function with the same in Superclass
		{
			return 3.14 * m_db_radius * m_db_radius;
		}

	protected:
		double m_db_radius;
};

class Rectangle : public Shape
{
	public:
		Rectangle(double _width, double _height)
		{
			m_db_height = _height;
			m_db_width = _width;
			cout << "Rectangle()"<<endl;
		}
		
		~Rectangle()
		{
			cout << "~Rectangle()" <<endl;	
		}

		double calc_area()  // hide the function with the same in the base class!
		{
			return m_db_height * m_db_width;
		}

	protected:
		double m_db_width;
		double m_db_height;

};
// The virtual function should have the same interface!!!
// int super class and sub class
// i.e. same return type, parameter list, function name!!!!

int main()
{
	// instantiate from the heap!!!!! Allocate, Check, Work with it, and release/ free up, reassigned NULL!!!
	// Subclass object is A Superclass Object. Hence, the base class pointer can points to the child class object but it can only access the base part!!!!!
	Shape * p1 = new Circle(2.34);
	Shape * p2 = new Rectangle(4.6, 7.8);
	if((!p1) || (!p2))
	{
		cout << "Fails to allocate memory to p1 or p2!!!" << endl;		
	}

/*
The binding of function prototype to the definiton is done at compile-time in accordance with the pointer or reference type rather than the conten of the pointer the object pointed to by the reference!!!
Recall that C++ is a static language which check the type at compile-time!
*/
	p1->calc_area();   // Pointer to base class can only access base-class part!!!!!
	p2->calc_area();
	/* p1->Circle::calc_area(); */// Circle is not a base of Shape so this expression is an error!!

	// The occupied heap memory should be released by hand!!!
	// Otherwise this memory remain taken up even if the program execution ends!
	delete p1;
	p1 = NULL;  // avoid that p1 points to the already released heap memory
	delete p2;
	p2 = NULL;

}
