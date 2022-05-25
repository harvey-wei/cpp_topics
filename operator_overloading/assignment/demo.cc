#include <iostream>
using namespace std;

class ComplexNumber{
private:
int real;
int imaginary;
public:
ComplexNumber(int real, int imaginary){
	this->real = real;
	this->imaginary = imaginary;
}
void print(){
	cout<<real<<" + i"<<imaginary;
}
ComplexNumber operator+ (ComplexNumber c2){
	ComplexNumber c3(0,0);
	c3.real = this->real+c2.real;
	c3.imaginary = this->imaginary + c2.imaginary;
	return c3;
}
};
int main() {
	ComplexNumber c1(3,5);
	ComplexNumber c2(2,4);
	ComplexNumber c3 = c1 + c2;
	c3.print();
	return 0;
}

/* The statement ComplexNumber c3 = c1 + c2; is internally translated as
   ComplexNumber c3 = c1.operator+ (c2); in order to invoke the operator function.
   The argument c1 is implicitly passed using the ‘.’ operator.
   The next statement also makes use of the dot operator to access the member function print and
   pass c3 as an argument. Thus, in order to ensure a reliable and non-ambiguous system of
   accessing class members, the predefined mechanism using class member access operators is
   absolutely essential. Besides, these operators also work on names and not values and there is
   no provision (syntactically) to overload them. */
