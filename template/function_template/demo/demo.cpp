/*
Basic Idea behind template is to pass data type as an parameter to a class or a function, termed class template or function template, respectively.

1.template
2.class has the same effect with typename!!
3. angle brackets <> !!!!

template <typename T> type as template parameter
template <class T>
template <int size> variable as template parameter

template <typename T, typename C>  comma-separated list  There must be one typename for one parameter!
template <typename T, class U>   // legal
template <typename T, int size>  // legal

template vs function overloading!
Recall that the difference between regular function and function template is that function template has template parameter(type or variable) as additional parameters!
Hence, function template can also be overloaded even using template parameters!
template <typename T>
void display(T a);
function templates can not be instantiated until they are used!!!

template <typename T>
void display()
Notice that, the return type of all these 4 functions are not same. Overloaded functions may or may not have different return type but it should have different argument(s). return type can not lead to overloading!!!!
// Error code
int test(int a) { }
double test(int b){ }
The number and type of arguments passed to these two functions are same even though the return type is different. Hence, the compiler will throw error.

Q1: What is the Generic Programming?
Generics is the idea to allow type (Integer, String, … etc and user-defined types) to be a parameter to methods, classes and interfaces.
"Same Logic but different data types!"

Q2: How to achieve Generics?
Generics can be implemented in C++ using Templates. Template is a simple and yet very powerful tool in C++.
Generic Functions using Template(function template)
Generic Class using Template(class template).
Like function templates, class templates are useful when a class defines something that is independent of data type. Can be useful for classes like LinkedList, binary tree, Stack, Queue, Array, etc.

For more details on Generic Programming in C++, consult the post at https://www.geeksforgeeks.org/generics-in-c/

*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// put template <> onto the top of function head/prototype/interface to declare in function template!!
template <typename T>   // typename T is to declare a data type parameter
void display(T a)
{
	cout << a << endl;
}


template <typename T, class S> // multiple data types
void display(T a, S b)
{
	cout << a << ", " << b << endl;
}

template <typename T, int KSize>  // data type and variable
void display(T a)
{
	for(int i(0); i < KSize; i++)
	{
		cout << a << endl;
	}
}

// All above function templates will be overloaded once template parameters are instantiated!!!
int main()
{
	/* display<int>(10);  // If <int> is omitted,then compiler will automatically imply it. It is strongly recommended to state the template parameter(data type or variable) explicitly. */
	/* display<double>(10.89); */
	/* display<string>("Generic Functions!"); */

	display<int, double>(5, 10.45);
	display<int, 5>(100);

	return 0;
}
