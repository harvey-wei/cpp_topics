#include <iostream>
using namespace std;

/**
 * https://stackoverflow.com/questions/33210169/how-to-use-noexcept-in-c-or-how-does-it-work
 * https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/
 */
/* void foo() noexcept     // see the noexcept specifier */
void foo()
{
    throw 42;
}

int main()
{
    try
    {
        foo();
    }
    catch(...)
    {
        cerr<<"exception caught\n";
    }
    return 0;
}


/**
 * Q: What is meant by (...)
 * A: In C++, (...) usually means something like "Any number of things of any types" whereas ()
 *    usually means "Nothing."
 * Ref: https://stackoverflow.com/questions/36737602/why-three-points-in-catch-block-is-exist
 *
 * Q: Implicitly non-throwing functions
 * A: Ref: https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/
 *
 * Q: Is nonexcept operator checked at compile time or at runtime?
 * A: The noexcept operator is checked statically at compile-time, and doesn't actually evaluate
 *    the input expression.
 *
 * Q: What is stack unwinding in c++?
 * A: As you create objects statically (on the stack as opposed to allocating them in the heap
 *    memory) and perform function calls, they are "stacked up".
 *    When a scope (anything delimited by { and }) is exited (by using return XXX;, reaching the end of
 *    the scope or *throwing an exception*) everything within that scope is destroyed (destructors are
 *    called for everything). This process of destroying local objects and calling destructors is called
 *    stack unwinding.
 *
 * Q: Why destructor should not throw an exception?
 * A: The C++ specifications state that you should never throw an exception before any existing
 *    exception has been handled.
 */
