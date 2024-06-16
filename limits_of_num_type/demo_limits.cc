#include <iostream>
#include <climits> // INT_MIN and INT_MAX
#include <limits> // 

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

       CAUTION when assigning the min of float or double during max_finding.
       DON'T erroneously assign std::numeric_limits<float>::min() to max_val.
       Instead, using the negative of std::numeric_limits<float>::max(),
       ** -std::numeric_limits<float>::max() **
    */
    std::cout << "The positive min of float32: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "The max of float32: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "The real min of float32: " << -std::numeric_limits<float>::max() << std::endl;

    std::cout << "The min of int: " << INT_MIN << std::endl;
    std::cout << "The max of int: " << INT_MAX << std::endl;


    /*
     * /build/a.out
     * The int32 range: -2147483648~2147483647
     * The positive min of float32: 1.17549e-38
     * The max of float32: 3.40282e+38
     * The real min of float32: -3.40282e+38
     */
    return 0;
}

