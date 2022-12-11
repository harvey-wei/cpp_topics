#include <random>
#include <iostream>


int main() {
    /* step 1: set up an engine */
    /* std::random_device rd; */
    /* std::random_device() creates an object
       (std::random_device())() generates a uniformly distributed random number as seeding value of std::mt19937
       std::mt19937 generates almost the uniformly distributed random value.
       rng is a functor to generate uniformly distributed random number.
    */
    std::mt19937 rng((std::random_device())()); // mt stands for Mersenne twister.

    /* step 2: specify the distribution type. */
    std::uniform_int_distribution<int> uniform_int_dist(1, 6);  // inclusive
    std::uniform_real_distribution<double> uniform_real_dist(10, 20); // inclusive
    std::normal_distribution<double> normal_dist(0, 1); // mean = 1, std_dev = 1

    /* step 3: get random numbers */
    const int cnt = 5;
    for (int i = 0; i < cnt; ++i)
    {
        /* Inverse transform sampling to generate target distributed random number. */
        std::cout << uniform_int_dist(rng) << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < cnt; ++i)
    {
        std::cout << uniform_real_dist(rng) << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < cnt; ++i)
    {
        std::cout << normal_dist(rng) << " ";
    }

    return 0;
}

/*
   Q: Why does the modulo operation not preserve the uniformity of the uniform operand for rand()?
   A: https://stackoverflow.com/questions/7114043/random-number-generation-in-c11-how-to-generate-how-does-it-work

   Q: Why can we get any kind of desired distribution from uniform distribution?
   A: https://en.wikipedia.org/wiki/Inverse_transform_sampling

   Q: What is std::random_device?
   A: std::random_device is supposed to be like an improved version of seeding with time(NULL).
   Ref: https://stackoverflow.com/questions/39288595/why-not-just-use-random-device.

   Q: What is std::std::mt19937?
   A: std::mt19937  is a very simple and reliable random generator whose implementation derives from
   the original mt19937 paper.
   Ref: https://stackoverflow.com/questions/39288595/why-not-just-use-random-device

   Q: Why to use mt19937 instead of rand()
   A: rand() use old linear congruent LC algorithm. First, rand() need you to invoke srand(time(0))
   on every run to ensure that it generates different sequence of numbers. Second, rand() produces
   integers ranging from 0 to RAND_MAX by uniform distribution, inclusive. To specify the range,
   you have to utilize modulo operation which break the uniformity. However, the mt19937 use std::
   random_device to seed on every run for you and ensure the distribution type.
*/
