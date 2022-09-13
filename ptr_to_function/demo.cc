// ref: http://websites.umich.edu/~eecs381/handouts/Pointers_to_memberfuncs.pdf
// Whenever function is passed anywhere, it decays into a pointer to function.

#include <iostream>

class A
{
    public:
        void f();
        void g(int a, int b);
};

void A::g(int a, int b)
{
    int s = a + b;
    std::cout << "The sum is " << s << std::endl;
}

void A::f()
{
    // declare pmf as pointer to A member function,
    // taking two integers and returning void
    void (A::*pmf)(int, int);
    // set pmf to point to A's member function g using address operator
    // address is a must unlike normal function pointer.
    // https://www.geeksforgeeks.org/function-pointer-in-c/
    pmf = &A::g;
    /* pmf = A::g;  // report error */
    // call the member function pointed to by pmf points on this object
    // * is a must unlike regular function pointer
    (this->*pmf)(1, 21); // calls A::g on this object

    // typedef for function pointer
    typedef void (A::*ptr_to_func_t)(int, int);
    ptr_to_func_t pmf_new = &A::g;
    (this->*pmf_new)(21, 20);
}

int main()
{
    A a_obj;
    a_obj.f();
    return 0;
}
