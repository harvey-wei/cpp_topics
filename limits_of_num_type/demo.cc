#include <iostream>

bool is_big_endian()
{
    // ref: https://stackoverflow.com/questions/1001307/detecting-endianness-programmatically-in-a-c-program
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01020304}; // 16909060

    /* Is big place value in the first byte? */
    std::cout << bint.i << std::endl;
    return bint.c[0] == 1;
}

int main()
{
    std::cout << "Is big endian? "<< is_big_endian() << std::endl;
    /* The way the computer stores the int does not affect the literal value of the int! */
    int my_int;
    my_int = 0xFFFFFFE2; // The 2's complement of -30.

    unsigned int my_uint;
    my_uint = 0x80000001; // 1000 0000 0000 0000 0000 0000 0000 0001 = 2147483648 + 1

    int my_sint = 0x80000001; // - (0111 1111 1111 1111 1111 1111 1111 1110 + 1 = 2147483647)

    std::cout << "my_int is " << my_int << std::endl;
    std::cout << "my_uint is " << my_uint << std::endl;
    std::cout << "my_sint is " << my_sint << std::endl;

    return 0;
}
