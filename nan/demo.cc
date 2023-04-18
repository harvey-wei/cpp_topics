#include <iostream>
#include <limits>
#include <cmath>

int main()
{
    std::cout << std::numeric_limits<double>::quiet_NaN()     << ' ' // nan
              << std::numeric_limits<double>::signaling_NaN() << ' ' // nan
              << std::acos(2)    << ' '   // nan due to the out of range of the cosine value
              << std::tgamma(-1) << ' '   // nan
              << std::log(-1)    << ' '   // nan , -1 is out of the domain of log
              << std::sqrt(-1)   << ' '   // -nan
              << 0 / 0.0         << '\n'; // -nan, division by zero


    std::cout << "NaN == NaN? " << std::boolalpha
              << ( std::numeric_limits<double>::quiet_NaN() ==
                   std::numeric_limits<double>::quiet_NaN() ) << '\n';
}

/*
 * \ref https://en.cppreference.com/w/cpp/types/numeric_limits/quiet_NaN
 * quiet_NaN vs signaling_NaN
 *
 * When an operation results in a quiet NaN, there is no indication that anything is unusual until
 * the program checks the result and sees a NaN. That is, computation continues without any signal
 * from the floating point unit (FPU) or library if floating-point is implemented in software.
 * A signalling NaN will produce a signal, usually in the form of exception from the FPU.
 * Whether the exception is thrown depends on the state of the FPU.
 *
 * \ref
 * https://stackoverflow.com/questions/18118408/what-is-the-difference-between-quiet-nan-and-signaling-nan
 */
