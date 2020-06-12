#include "Array.h"
#include "iostream"
using namespace std;


Array::Array(int len)
{
	this->len = len;  
	// this represent the address the object of the class 
	// So this should be followed by arrow(->)!!
	cout << "Array()" <<endl;
}
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
Array* Array::print_info()  // reference as return type!!!
{
	cout << "The value of this pointer" <<endl << this <<endl;
	cout << "len =" <<len <<endl; // len is what????
	return this; // this is a pointer, so * fetch the object to which this points!!
}
// return bu reference: not return value but the variable itself(i.e. return an implicit pointer)
