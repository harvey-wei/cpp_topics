#include <iostream>
#include <functional> // for bind()

using namespace std::placeholders; // for placeholders like _1, _2, etc.

double
my_divide(double x, double y)
{
    return x / y;
}
class Foo {
    public:
        void print_sum(int n1, int n2)
        {
            std::cout << n1 + n2 << '\n';
            std::cout << "n1: " << n1 << " vs " << "n2: " << n2 << std::endl;
        }
        int data = 10;
};

int
main()
{
    // _1 is the first argument to fn_half
    // _1 is assigned to x while 2 is assigned to y of my_divide
    // Hence, fn_half(x) returns x/2
    // For regular function name, it acts as function pointer.
    /* auto fn_half = std::bind(my_divide, _1, 2); */
    auto fn_half = std::bind(&my_divide, _1, 2);
    std::cout << fn_half(10) << std::endl;

    // The first argument to std::bind() is an object identifying how to call a function.
    // In the above case it is a pointer to function with type double(*)(double, double).
    // Any other callable object with a suitable function call operator would do, too.

    // For member function, its name DOES NOT act as function pointer implicitly!.
    // You need address operator!
    Foo foo;
    // To bind to member function, you need pass pointer to class object as the second argument!
    // 95 is given to the 1st arg of print_sum while the 1st arg of f is assigned to 2nd arg of
    // print_sum.
    auto f = std::bind(&Foo::print_sum, &foo, 95, _1);
    f(5); // print_sum(95, 5)

    return 0;
}

/*
   ref: https://stackoverflow.com/questions/37636373/how-stdbind-works-with-member-functions
   ref: https://www.geeksforgeeks.org/bind-function-placeholders-c/
*/
