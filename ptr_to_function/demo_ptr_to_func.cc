// ref: https://stackoverflow.com/questions/37636373/how-stdbind-works-with-member-functions
// When a function is passed anywhere it decays into a pointer.

// ref: https://www.geeksforgeeks.org/function-pointer-in-c/

#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
 printf("Value of a is %d\n", a);
}

int main()
{
    // fun_ptr is a pointer to function fun()
    // verbose form with address operator &
    // void(int) is the signature of function, i.e. takes a int and return none
    void (*fun_ptr)(int) = &fun;

    // simple form without address operator & since function name itself is actually a pointer to
    // itself.
    void (*fun_ptr_simple)(int) = fun;

    /* The above line is equivalent of following two
    void (*fun_ptr)(int);
    fun_ptr = &fun;
    */

    // Verbose form to invoke func() using dereferencing operator *
    (*fun_ptr)(10);

    // Simple form.
    fun_ptr(10);

    // simple form to invoke func() without *
    fun_ptr_simple(10);

    return 0;
}

