#include <iostream>

int main()
{
    // get the round-down halve of negative integers, you are better off add 1 before shifting! 
    int a = -1020;
    a = (a + 1) >> 1;
    std::cout << "Half of a: " << a << std::endl;

    int b = -1021;
    b = (b + 1) >> 1;
    std::cout << "Half of b: " << b << std::endl;

    return 0;
}

/*
https://stackoverflow.com/questions/4009885/arithmetic-bit-shift-on-a-signed-integer
https://leetcode.com/problems/divide-two-integers/solution/

One potential pitfall with the right-shift operator is using it on negative odd numbers. Two's complement makes the result one-off what you would expect/ probably wanted. This happens in all the programming languages we've checked, although there could be a few that behave differently.
The solution is to add 1 before doing the bit-shift on a negative number. This way, it'll be "correct" regardless of whether the number was odd or even.

As of c++20 the bitwise shift operators for signed integers are well defined.

The left shift a<<b is equivalent to a*2^b modulus 2^N where N is the number of bits in the resulting type. In particular 1<<31 is in fact the smallest int value.

The right shift a>>b is equivalent to a/2^b, rounded down (ie. towards negative infinity). So e.g. -1>>10 == -1.
*/
