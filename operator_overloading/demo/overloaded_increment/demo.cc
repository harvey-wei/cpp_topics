// C++ program to demonstrate
// prefix increment operator overloading

#include <bits/stdc++.h>
using namespace std;

class Integer {
private:
	int i;

public:
	// Parameterised constructor
	Integer(int i = 0)
	{
		this->i = i;
	}

	// Overloading the prefix operator, ++i
    // the expr value is the updated i. Hence, we return a reference to i
    Integer& operator++()
    {
        ++i;
        return *this;
    }

    // Overloading the postfix operator, i++
    // The expr value is the old one. Thereby, we can not return a reference but a copy of the old.
    // int is just a flag for postfix.
    Integer operator++(int)
    {
        Integer old = *this;
        ++i;

        return old;
    }

	/* Integer& operator++() */
	/* { */
	/* 	++i; */
	/* 	// returned value should be a reference to *this */
	/* 	return *this; */
	/* } */

	// Function to display the value of i
	void display()
	{
		cout << "i = " << i << endl;
	}
};

// Driver function
int main()
{
	Integer i1(3);

	cout << "Before increment: ";
	i1.display();

	// Using the pre-increment operator
	Integer i2 = ++i1;

	cout << "After pre increment: " << endl;
	cout << "i1: ";
	i1.display();
	cout << "i2: ";
	i2.display();

    // Using the post-increment operator
    /* Integer i2 = i1++; */
    /* cout << "After post increment: " << endl; */
    /* cout << "i1: "; */
    /* i1.display(); */
    /* cout << "i2: "; */
    /* i2.display(); */
}
