/* 
Virtual is intended to use the pointer or reference to superclass to call the related function in the subclass. 
   You can image the member function in the subclass as the member function of the superclass provided that both of them share the same function prototype/interface(same return type, same function name and same parameter list!) by declare both of them as virtual!!!! 
   Ordinarily, pointer or reference to the superclass can not access the derived part. Hence, the keyword virtual(almost or very nealry the thing described!)
*/
		

/* 
   When will the virtual function make the difference?

   When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function. 
   Note that the base's version and derived's verison should possess the same function prototype!!!
*/

/*
It is good practice to prefix both the related functions with virtual keyword!!!!
*/

/*
For more details about virtual function, refer to the post at https://www.geeksforgeeks.org/virtual-function-cpp/
*/

/*
Q1:What is binding?
Binding can be interpreted as the binding of the function prototype to the associated definition. 

Q2: How to make the difference between Early Binding and Late Binding?
Binding can happen at run-time and compile-time. Compile-time binding(Early Binding) is in accordance with the type of pointer or reference while run-time binding(Late Binding) is done according to the content of pointer or reference.

Q3: Examples of late and early binding.
Function/Operator overloading is an  example of early binding occurring at compile-time whereas virtual member function is an example of late bindiong happening at run-time.

Q4: What is polymophism in C++?
The word polymorphism means having many forms. In the broad sense, we can define polymorphism as the ability of a message to be displayed in more than one form. For example, for 

Q5: What is the polymophism for?(Why use the polymorphism?)/ What is the use?
Virtual functions allow us to create a list of base class pointers(references) and call methods of any of the derived classes without even knowing kind of derived class object.

Q6: How does the compiler perform runtime resolution?(vtable & vptr)

The compiler do two things to server the purpose:
1.vtable. A table of pointers to virtual functions, maintained per class for both base class and derived class!

	Irrespective of object is created or not, a static array of function pointer called VTABLE where each cell contains the address of each virtual function contained in that class
2.vptr, pointer to the vtable, created per object instance!!!!! 
	If object of that class(base class or derived class)is created then a virtual pointer(VPTR) is inserted as a data member of the class to point to VTABLE of that class. For each new object created, a new virtual pointer is inserted as a data member of that class. vptr points to the inital address of the VTABLE of the same class !!!
To sum up, vtable, short for table of pointers to virtual functions, is a static array of fuction pointers created per class whereas the vptr, a shorthand for pointer to (inital address)vtable, is pointer to the VTABLE per object instance created per object instance!!! The address of the virtual function to be called is figureed out by shifting the vptr per object instance!!
*/
/*
The posts at https://www.geeksforgeeks.org/virtual-function-cpp/ and https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/ offer good tutorials on the working of the virtual function!!
*/
/*
Q7: virtual function of base is overridden(re-defined) by the virtual function with same prototype of the derived!!!!!
That base function is said to be overridden.
Function overriding on the other hand occurs when a derived class has a definition for one of the member functions of the base class.
Refer to the post at https://www.geeksforgeeks.org/polymorphism-in-c/ for the classificatio of polymorphism!
*/

/*
Q8: What kind of functions can virtual keyword modify? Restriction on virtual keyword!!
"virtual" can not modify regular function such as global function!
"virtual" can not qualify the static member function!! Recall that static member function is class function. Hence it can not be virtual function! Virtual Function is dependent on the object instance of the class while the static member funciton is independent of the class object instance!!!! The former achieves the run-time polymorphism and the latter attains the compile-time polymorphism!!!
"virutal" can not qualify the inline function!
"virtual" can not qualify the constuctor!!!!
In summary, "virtual" function is used to modify the non-static member function and destructor!!!!!
As a side note, a set of related virtual function should have the same function prototype while a set of overleaded functions or opertors are supposed to have the same function name only!!!
If no virtual(overridden) version occurs in the derived class, then virtual functions from the base class is inherited by derived class. More specifically, base class and derived calss have two different vtables but the inherited virtual function has only one single copy in the memory, which means the base object and derived object will access the same memory space for that function. Of course, the base class object and derived class object have 2 distinct vptrs to their own vtables!!!!

If virtual version appears in the derived class, then the ptr in the vtable for derived class is displaced by the new address of the overridden version in the derived class provided that the virtual function is accesed using pointer of base class type pointing to derived class object!!!

Mechanism: vptr for class object(both base and derived class)-> vtable for class(both base and derived class)-> the required virtual function in the code segment
Q9: overridden vs hiding
Hiding means that the function in the derived class hides the function with the same name but without virtual keyword!!!
Overridden is done for functio with same functio prototype(same return type, same function name, same parameter list) and virtual keyword as prefix!!

Q10: Is the virtual keyword in derived class able to be omitted?
The virtual keyword in the derived class can be left out but in that case the compiler will automatically add "virtual" for you. Thus, it is strongly recommended to write out the "virtual" before the member funciton in the derived class explicitly for better readability!!!
*/

#include <iostream>
#include <string>
using namespace std;

class Shape 
{
	public:
		Shape()
		{
			cout << "Shape()" << endl;
		}
// Using superclass pointer or reference to the subclass complies with the spirit of the generic programming!!!

/*
In the case the base class pointer is used to point to the derived class object.
Base_cls_ptr will also call the destructor of the derived class's destructor to release the heap memory!

Repeat the principle of the virtual function! When pointer or reference to superclass points to or refers to the subclass(is A), it can call the derived's version of the function with the same prototype as the base class!!!(one example of runtime polymophism!!!!)
*/
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
		Circle(double _r)
		{
			cout << "Circle()" << endl;
			m_db_radius = _r;
		}

		virtual ~Circle()
		{
			cout << "~Circle()" <<endl;
		}

		virtual double calc_area()
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
		
		virtual ~Rectangle()
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
// The virtual function should have the same interface/prototype!!!
// int super class and sub class
// i.e. same return type, parameter list, function name!!!!
int main()
{
	// instantiate from the heap!!!!!
	Shape * ptr[2]; // Array of pointers to the base class!!!
	ptr[0] = new Circle(2.34);
	ptr[1] = new Rectangle(4.6, 7.8);
	
	// Late binding (Runtime polymophism)
    cout << "The area of Circle"<< ptr[0]->calc_area() << endl;
	cout << "The area of Rectangle" << ptr[1]->calc_area() << endl;
	/* p1->Circle::calc_area(); */// Circle is not a base of Shape so this expression is an error!!

	// The occupied heap memory should be released by hand!!!
	// Otherwise this memory remain taken up even if the program execution ends!
	delete ptr[0];
	ptr[0] = nullptr;  // avoid that p1 points to the already released heap memory
	delete ptr[1];
	ptr[1] = nullptr;

	// What is nullptr?
	// Wherever you were writting NULL before, you should use nullptr instead.
	// nullptr is introduced since c++ 11
	// NULL is zero and zero is an integer!!!!
	// nullptr is not convertible to ingteger zero but convertible to bool false!!!

}


