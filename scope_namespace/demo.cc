#include <iostream>

int a = 10; //this a is defined in global namespace
       //which means, its scope is global. It exists everywhere.

namespace N
{
     int a = 100;  //it is defined in a non-global namespace called `N`
             //outside N it doesn't exist.
}


class A
{
    public:
        int a = 20;  //its scope is the class itself. Outside of A, it doesn't exist.
};

void f()
{
    int a = 1000;  //its scope is the function itself. outside the function, a doesn't exist.
    std::cout << "a in f: " << a << std::endl;
    std::cout << "a in namespace N: " << N::a << std::endl;
    std::cout << "a in global namespace: " << ::a << std::endl;

    {
        int a = 2; //the curly braces defines this a's scope!
        std::cout << "a in a scope of f: " << a << std::endl;
    }

    A a_inst = A();

    std::cout << "a in class A: " << a_inst.a << std::endl;
}

int main()
{
    f();

    return 0;
}

/**
 * Q: What is scope?
 * A: A scope is defined by namespace, functions, classes or simply {}.
 *
 * Q: :: w/o namespace?
 * A: :: indicates global namespace
 *    A symbol, by default, exists in a global namespace, unless it is defined inside a block starts
 *    with keyword namespace, or it is a member of a class, or a local variable of a function
 *
 * Ref: https://stackoverflow.com/questions/10269012/global-scope-vs-global-namespace
 */
