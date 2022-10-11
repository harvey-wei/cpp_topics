#include <iostream>

int main()
{
    int a = -5;
    int b = -6;

    std::cout << a << " % 2: " << (a & 1) << std::endl;
    std::cout << b << " % 2: " << (b & 1) << std::endl;

    int c = 109091;
    std::cout << c << " % 2: " << (c & 1) << std::endl;

    return 0;
}

