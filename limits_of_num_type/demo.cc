#include <iostream>
#include <limits>

int main()
{
    /* For signed integer of length N-bits, it ranges from -2^(N-1) ~ (2^(N-1) - 1). In other
    words, each positive integer has a corresponding negative integer but -2^(N-1) does not
    correspond to any positive integer. - pos_int may cause underflow problem.*/
    std::cout << "The int32 range: " << INT32_MIN << "~" << INT32_MAX << std::endl;

    /* float is symmetric in minimum/maximum values. */
    /* Caveat std::numeric_limits<float>::min() is NOT the min of float BUT the min positive number
       it can represents. (underflow?)
        Due to the symmetry of floating point number, min of float is equal to the negative of it
        max.
    */
    std::cout << "The positive min of float32: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "The max of float32: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "The real min of float32: " << -std::numeric_limits<float>::max() << std::endl;
    return 0;
}
