#include <iostream>

void print_8bit_bin(const char num)
{
    // This is another way of find the binary representation of decimal numbers.
    // Trick: shift 1 to select the bit of char or integers like identity matrix!
    // int & 1 == 0 -> even otherwise odd
    // bitwise and & can identify the bit!
    // https://www.programiz.com/cpp-programming/bitwise-operators
    std::cout << "num " << int(num) << "'s binary representation" << std::endl;
    for (int i = 7; i >= 0; --i)
    {
        if (num & (1 << i))
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }

    std::cout << std::endl;

}

int main()
{
    char num = -25;
    std::cout << "num is ";
    print_8bit_bin(num);

    // bitwise operator is not in-place! 
    /* char num_ = num << 2; */
    /* std::cout << "num is "; */
    /* print_8bit_bin(num); */
    /* std::cout << "num_ is "; */
    /* print_8bit_bin(num_); */

    for (int i = 0; i < 8; ++i)
    {
        std::cout << "shift num to the right by " << i << "bits" << std::endl;
        print_8bit_bin(num >> i);
    }

    std::cout << "After shifting num is  ";
    print_8bit_bin(num);

    std::cout << (-1 >> 10);


    return 0;
}

/*
   ref: https://www.codespeedy.com/right-shift-negative-numbers-in-cpp/
*/
/*
    ref: https://leetcode.com/problems/divide-two-integers/solution/
    While you might be tempted to use multiplication and division for a few "simple" tasks, this is unnecessary. Here are some alternatives:
    Instead of a = a * -1 for making numbers negative, use a = -a.
    Instead of using a / 2 for dividing by 2, use the right shift operator; a >> 1.
    Instead of using a * 2 for doubling, use a = a + a, a += a, or even the left shift operator; a << 1.
*/

/*
   Q: How does the computer store integers?
   A: ref: https://en.wikipedia.org/wiki/Two%27s_complement

   Q: Is the sign bit after bitwise operation fixed?
   A: The MSB bit must be fixed at all times.
   Ref: https://www.codespeedy.com/right-shift-negative-numbers-in-cpp/
   Ref: https://stackoverflow.com/questions/4009885/arithmetic-bit-shift-on-a-signed-integer
   The right shift a>>b is equivalent to a/2^b, rounded down (ie. towards negative infinity)

   Q: How does the computer store real numbers?
   A: https://www.cs.mcgill.ca/~cs573/fall2002/notes/lec273/lecture3/#212

   https://stackoverflow.com/questions/21819682/is-integer-multiplication-really-done-at-the-same-speed-as-addition-on-a-modern
*/
