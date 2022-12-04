#include <iostream>
#include "counter.h"

extern void test(); // declaration

int main()
{
    std::cout << "main: g_counter value: " << g_counter << ", address: " << &g_counter << std::endl;
    dump();
    std::cout << "main: g_counter value: " << g_counter << ", address: " << &g_counter << std::endl;
    test();
    std::cout << "main: g_counter value: " << g_counter << ", address: " << &g_counter << std::endl;

    return 0;
}
