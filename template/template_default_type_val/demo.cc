#include <iostream>
using namespace std;

template <class T, typename U = char, int size = 10> class A {
public:
    T x;
    U y;
    A() { cout << "Constructor Called" << endl;
    cout << "size: " << size << std::endl;
    }
};

int main()
{
    A<char> a; // This will call A<char, char>
    return 0;
}

/** We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying
  * max or min values or any other constant value for a particular instance of a template.
  * The important thing to note about non-type parameters is, they must be const.
  * The compiler must know the value of non-type parameters at compile time.
  * ref: https://www.geeksforgeeks.org/templates-cpp/
  */
