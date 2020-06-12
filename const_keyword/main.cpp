#include "iostream"
#include "string"
// const variable must be either initialized when created or initialized via initializer list in constructor for a class!
// const keyword meets pointer
using namespace std;

int main(){
const int *ptr_0 = NULL;   // NULL is reserved keyword meaning addressing no  object and with value zero.
// const int *p defines a variable pointer to an constant integer

int const *ptr_1 = NULL;   // An alternative syntax which does the same thing as above, i.e. declare a variable pointer to an constant integer

int w = 103;
int * const ptr_3 = &w; //  ptr_3 is constant pointer to an variable integer

// ptr_0 and ptr_1 pont to read-only variable
/* *ptr_0 = 10; // report error */
/* *ptr_1 = 11; // report error */
int y = 1;
int x = 2;
int z = 3;
			

cout << ptr_0 << endl;
ptr_0 = &x;
cout <<	ptr_0 << endl;

cout << "The value of ptr_3: "  << ptr_3 << endl;
cout << "What the ptr_3 points to: " << *ptr_3 << endl;
*ptr_3 = 104;
cout << "What the ptr_3 points to: " << *ptr_3 << endl;
// ptr_3 itself is read-only, which means ptr_3 can not be reassigned a new address 
/* ptr_3 = &x; */
cout << "What the ptr_3 points to: " << *ptr_3 << endl;
cout << "What the ptr_3 points to: " << *ptr_3 << endl;

// Fusing the above two kinds of syntax, we obtain an constan pointer to an constant object
const int * const ptr_4 = &x;
int const * const ptr_5 = &z;
// Hence, the following statements give rise to error.
/* ptr_4 = &y; */
/* ptr_5 = &y; */
/* *ptr_4 = 1000; */
/* *ptr_5 = 2000; */




}
