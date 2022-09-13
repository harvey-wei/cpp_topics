// C++ code to demonstrate placeholder
// property 1
#include <iostream>
#include <functional> // for bind()
using namespace std;

// for placeholders
using namespace std::placeholders;

// Driver function to demonstrate bind()
void func(int a, int b, int c)
{
    cout << (a - b - c) << endl;
}

int main()
{
    return 0;
}
