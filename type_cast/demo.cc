#include <iostream>

using namespace std;
int main()
{
    // part 1: static_cast
    // It works on both type/class and pointer.
	float f = 3.5;
	int a = f; // this is how you do in C
	int b = static_cast<int>(f);

    // compile time error: invalid type cast from char* to int*
    /* char c = 'a'; */
    /* int* q = (int*)&c; */
    /* int* p = static_cast<int*>(&c); */

    // part 2: reinterpret_cast
    // Ref: https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
    // Notes:
    // 1. reinterpret_cast is only applied to pointer variable.
    // 2. It does not check if the source pointer type and target pointer type
    //    are the same or not.
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);

    cout << *p << endl;
    cout << *ch << endl;
    cout << p << endl;
    cout << ch << endl; // char* is a string.

    delete p;
    /* delete ch;  double free error sine both p and ch points to the same address*/

	cout << b;
}


/**
 * Q: What is meant by static in static_cast?
 * A: The word static here menas compile time. static_cast is a compile time
 *    casting operator and does things like implicit conversions between types
 *    like int to float or pointer to void*.
 * Ref: https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/
 */
