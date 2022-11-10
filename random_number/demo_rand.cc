// C++ program to demonstrate
// the use of rand()
// ref: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
// ref: https://stackoverflow.com/questions/52869166/why-is-the-use-of-rand-considered-bad
#include <cstdlib> // for rand() and srand()
#include <ctime>
#include <iostream>

int main()
{
	// This program will create same sequence of
	// random numbers on every program run because the seed (starting point) is always the same
    // as if srand(1) is called.
	for (int i = 0; i < 5; i++)
		std::cout << float(rand()) / float(RAND_MAX) << " ";
    /* returns a pseudo-random number in the range of [0, RAND_MAX). */
    /* RAND_MAX: is a constant whose default value may vary between implementations but it is
       granted to be at least 32767. */
    /*  It is uniform in this interval, which means that each number in this interval has the same probability to appear */

    std::cout << std::endl;

    for (int i = 0; i < 5; ++i)
    {
        std::cout << rand() % 10 << " ";
    }

    std::cout << std::endl;
    /* Standard practice is to use the result of a call to srand(time(0)) as the seed.
       However, time() returns a time_t value which varies every time and hence the pseudo-random
       number varies for every program call. */
     // Use current time as seed for random generator
    /* time_t curr_time; */
    srand(time(nullptr));
    /* To get the uniform integer in the range of 0 to 10.[0, 10) */
	for (int i = 0; i < 5; i++)
		std::cout << rand() % 10 << " ";
    std::cout << std::endl;

    /* To get uniform variate in the range of 0.0 to 1.0. */
	for (int i = 0; i < 5; i++)
		std::cout << float(rand()) / float(RAND_MAX) << " ";

	return 0;
}

/*
Q: What kind of probability distribution is the rand() distributed as?
A: Uniform distribution.
*/
