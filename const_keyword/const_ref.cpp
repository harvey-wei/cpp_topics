#include "iostream"
#include "string"
using namespace std;

// const meets reference

int main(){

// Recall that the reference is just a alias of the referenceed object and can not be reassigned
// reference must be initialized (when being created)
int x(4);
const int &y(x);    // y becomes constant
int &z(x);

x = 100;   //  The properties of x is not affected by the related reference.
cout << "The value of x is: " << x << endl;
cout << "The value of y is: " << y << endl;
cout << "The value of z is: " << z << endl;
/* y = 200;   // reports an error because y is a consatnt reference */ 
z = 300;   //  The value of x is also changed because z is an alias of x
cout << "The value of x is: " << x << endl;
cout << "The value of y is: " << y << endl;
cout << "The value of z is: " << z << endl;
cout << "Addresses of x: " << &x << endl;
cout << "Addresses of y: " << &y << endl;
cout << "Addresses of z: " << &z << endl;
// As is shown in the output, x, y and z are the same thing, i.e. share the same value and identical location in the memory. More importantly, any modification to any of them applies to all the other.

}
