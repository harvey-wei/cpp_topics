/*
Functors are objects that can be treated as though they are a function or function pointer. Functors are most commonly used along with STL.
*/

/*
A functor (or function object) is a C++ class that acts like a function. Functors are called using the same old function call syntax. To create a functor, we create a object that overloads the operator().
The line:
My_Functor(10);

is the same as:
My_Functor.operator()(10);
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Define A functor(A class acting like a function)
class increment
{
  private:
    int num;
  public:
    // constructor
    increment(int n)
      : num(n)
    {}

    // This operator overloading enables to call operator function() on objects of increment class

    int operator () (int arr_num) const   // forbidden to modify data member
    {
      return num + arr_num;
    }

};

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int to_add = 5;
  transform(arr, arr+n, arr, increment(to_add));
  // class (object) increment acts as a function
  // Functor is short for function object
  /*
     The above line amounts to
     increment obj(to_add);
     transform(arr, arr+n, arr, obj);
  */
  std::cout << 100 << std::endl;
}
