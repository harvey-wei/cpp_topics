#include <iostream>

int main()
{
    int a = -5;
    int b = -6;

    std::cout << a << " % 2: " << (a & 1) << std::endl;
    std::cout << b << " % 2: " << (b & 1) << std::endl;

    int c = 109091;
    std::cout << c << " % 2: " << (c & 1) << std::endl;

    /*
       bitwise with 1 to tell if a integer is even or odd.
       Understand it in binary representation of integer.
    */

    std::cout << "Is " << a << " odd? " << ((a & 1) ? "True" : "False") << std::endl;
    std::cout << "Is " << b << " odd? " << ((b & 1) ? "True" : "False") << std::endl;
    std::cout << "Is " << c << " odd? " << ((c & 1) ? "True" : "False") << std::endl;

    return 0;
}

