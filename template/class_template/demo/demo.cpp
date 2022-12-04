/*
Q1: How to define a class template?
   One subtlety of the member function definition of class template
   For the member function defined inside the class, definition remains the same while the definition  outside the class must follow the  following pattern:
   template <typename T, class U, int KSize>
   void MyArray<T, U, KSize>::display()  // Class Name must be followed by a pair of angle bracket enclosing type variable
   {

   }
Q2: How to use the class template?
ClassName must be followed by a pair of angle brackets enclosing a list of actual arguments (values of the template parameters!!!)
Like functio template, only if we specify the template arguments, the class template become instantiated!!!
*/

#include <iostream>
#include <string>
#include "My_Array.h"
using namespace std;

int main()
{
	My_Array<int, 5, 6> arr;
	arr.display(); // Since we have instantiated the class template, no need to add <> again!!


	return 0;
}
