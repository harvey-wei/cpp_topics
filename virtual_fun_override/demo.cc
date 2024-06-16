// A CPP program that uses override keyword so
// that any difference in function signature is
// caught during compilation
#include <iostream>
using namespace std;

class Base {
public:
	// user wants to override this in
	// the derived class
	virtual void func() { cout << "I am in base" << endl; }
};

class derived : public Base {
public:
	// did a silly mistake by putting
	// an argument "int a"
	/* void func(int a) override */
    virtual void func() override
	{
		cout << "I am in derived class" << endl;
	}
};

int main()
{
	Base b;
	derived d;

    Base& base_ref = d;
    base_ref.func();

	std::cout << "Compiled successfully" << endl;

	return 0;
}

/** Q: What is the virtual function?
  * A: A virtual function is a member function which is declared or even defined within a base class
  * and is re-defined (overridden) by a derived class. When you refer to a derived class object
  * using a pointer or a reference to the base class, you can call a virtual function for that
  * object and execute the derived class’s version of the function.
  * ref: https://www.geeksforgeeks.org/virtual-function-cpp/
  *
  * Q: Why to use the virtual function?
  * When you refer to a derived class object using a pointer or a reference to the base class.
  * Image a scenario, you have different kinds of LiDAR (single layer, multi-layer,
  * solid-state,etc.). You design a generic set of functions to process their point cloud. In order
  * to process different types of LiDARs in a unified way. You need to access different LiDAR
  *  classes using a pointer or reference to the generic parent LiDAR class.
  *
  * Q: What is function overriding in virtual function?
  * A: Function overriding is a redefinition of the base class function in its derived class with
  * the same signature i.e. return type and parameters.
  * ref: https://www.geeksforgeeks.org/override-keyword-c/
  *
  * Q: Why is better to use override keyword in the derived class?
  * A: It will make the compiler check the base class to see if there is a virtual function with
  * this exact signature. And if there is not, the compiler will show an error.
  * ref: https://www.geeksforgeeks.org/override-keyword-c/
  *
  * Q: Can virtual function be defined in both base class and derived class?
  * A: Yes.
  *
  * Q: What is the point of the *final* keyword after virtual function?
  * A: Sometimes you don’t want to allow derived class to override the base class’ virtual function.
  * C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier.
  * final virtual function can only be defined in base class.
  * https://www.geeksforgeeks.org/c-final-specifier/
  *
  * Q: overrid keyword
  * The override keyword in C++ explicitly specifies that a virtual function in a derived class
  * is intended to replace (or “override”) a virtual function in the base class with the same name.
  */
