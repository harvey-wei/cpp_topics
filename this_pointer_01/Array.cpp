#include "Array.h"
#include "iostream"
using namespace std;
/* Why we need "this" pointer?
   From the perspective of memory management, different instances/objects of the same class will take up different memory locations for the their respective data members but shar the same code segment for their member function operating on the data members. Then comes the question!
   How does the member function know from which object the data it operates on are?
   This is where the "this" pointer comes from. "this" is a pointer to the current  object of certain class!

*/

// Constuctor 
Array::Array(int len)
{
	this->len = len; // this->len is data member while len is a local variable to the constructor.  
	// this represent the address of the object of the class 
	// So this should be followed by right-pointing arrow(->)!!
	cout << "Array()" <<endl;
}

// Destructor
Array::~Array()
{
	cout << "~Array()" <<endl;
}

void Array::set_len(int len)
{
	this->len = len;
}

int Array::get_len()
{
	return this->len;
}

Array& Array::print_info()  // reference as return type!!!
{
	cout << "len =" <<len <<endl; // len is what????
	return *this; // this is a pointer, so * fetch the object to which this points!!
}
// return bu reference: not return value but the variable itself(i.e. return an implicit pointer)
