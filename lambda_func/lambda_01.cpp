#include <algorithm>
#include <cmath>
#include <iterator>

/*
   A lambda can introduce new variables in its body (in C++14), and it can also access, or capture, variables from the surrounding scope.
*/

void abssort(float* x, unsigned int n)
{
    std::sort(x, x + n,
            // lambda expression begins
            // define the less than operator
            // smaller is sorted before the larger.
            [](const float& a, const float& b) {
                return (std::abs(a) < std::abs(b));
            });
}
