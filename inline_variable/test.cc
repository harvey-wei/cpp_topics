#include "counter.h"

void test()
{
    std::cout << "test: g_counter value: " << g_counter << ", address: " << &g_counter << std::endl;
    dump();
    std::cout << "test: g_counter value: " << g_counter << ", address: " << &g_counter << std::endl;

    return;
}
