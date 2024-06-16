#include <iostream>
#include <string>


using namespace std;
// Here the user-defined class Coordinate
// Recall the derived class destructor is executed before that of the base class!!!
// Virtual provides a mechanism to execute the derived class destructor by the base class pointer!!!
// The prequsite is the same as that for virtual member function for polymorphism, using the pointer (reference)of base class type to point to (reference) the derived class object!

// The working of the virtual destructor is exactly the same as that of virtual function, namely achieved by  VTABLE and VPTR!!!!!!
class Coordinate
{
	public:
		Coordinate(double _x, double _y)
		{
			m_int_x = _x;
			m_int_y = _y;
			cout << "Coordinate()" << endl;
		}

		// Declaring destructor as virtual is good practice to avoid memory leakage when instantiating from the heap!
		virtual ~Coordinate()
		{
			cout << "~Coordinate()" << endl;
		}

	private:
		double m_int_x;
		double m_int_y;
};


class Shape
{
	public:
		Shape()
		{
			cout << "Shape()" << endl;
		}

		virtual ~Shape()
		{
			cout << "~Shape()" <<endl;
		}

		virtual double calc_area()
		{
			cout <<"Shape->calc_area()"<< endl;

			return 0;
		}
};


class Circle : public Shape
{
	public:
		Circle(double _x, double _y, double _r)
		{
			cout << "Circle()" << endl;
			m_db_radius = _r;
			p = new Coordinate(_x, _y);  // apply for the heap memory!!!
		}

		virtual ~Circle()
		{
			delete p;   // don't forget to free up the memory in heap!!
			p = NULL;
			cout << "~Circle()" <<endl;
		}

		virtual double calc_area()
		{
			return 3.14 * m_db_radius * m_db_radius;
		}

	protected:
		double m_db_radius;
		Coordinate *p;    // center of circle   // use the Coordinate but not inherit !!!!!!!
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

		virtual double calc_area()
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
	// instantiate from the heap!!!!!
	// The prerequisite is to access the destructor of derived using pointer or reference to base!
	Shape * p1 = new Circle(0,12.3, 10.1);
	Shape * p2 = new Rectangle(4.6, 7.8);
    cout << "The area of Circle"<< p1->calc_area() << endl;
	cout << "The area of Rectangle" << p2->calc_area() << endl;
	/* p1->Circle::calc_area(); */// Circle is not a base of Shape so this expression is an error!!

	// The occupied heap memory should be released by hand!!!
	// Otherwise this memory remain taken up even if the program execution ends!
	delete p1; // execute the destructor of derived first and then execute the destructor of th base due to the keyword virtual!!!!!
	p1 = nullptr;  // avoid that p1 points to the already released heap memory
	delete p2;
	p2 = nullptr;
}
