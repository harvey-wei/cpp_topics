#include <iostream>

// ref: https://www.learncpp.com/cpp-tutorial/unnamed-and-inline-namespaces/
namespace // unnamed namespace which is part of the parent namespace, i.e. global namespace.
{
    void doSomething() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    return 0;
}
