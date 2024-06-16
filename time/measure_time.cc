#include <chrono>
#include <utility>
#include <iostream>
#include <type_traits>
#include <vector>

/* timing: https://stackoverflow.com/questions/31391914/timing-in-an-elegant-way-in-c */
/* clock: https://stackoverflow.com/questions/13263277/difference-between-stdsystem-clock-and-stdsteady-clock */
/* std::forward, https://cplusplus.com/reference/utility/forward/ */
/* variadic: https://learn.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-170 */ /* function as typename: https://stackoverflow.com/questions/1174169/function-passed-as-template-argument */

int find_the_largest(std::vector<int> array)

#include <iostream>
#include <vector>

// Function to find the maximum element in an array
int findMax(std::vector<int> array) {
    if (array.empty()) {
        return INT_MIN;
    }
    
    int max = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    
    return max;
}

// Test cases
int main() {
    // Test case 1: Empty array
    std::vector<int> emptyArray;
    int maxEmptyArray = findMax(emptyArray);
    if (maxEmptyArray == INT_MIN) {
        std::cout << "Test case 1 passed. Empty array handled correctly." << std::endl;
    } else {
        std::cout << "Test case 1 failed. Empty array not handled correctly." << std::endl;
    }
    
    // Test case 2: Array with positive numbers
    std::vector<int> positiveArray = {3, 7, 2, 9, 5};
    int maxPositiveArray = findMax(positiveArray);
    if (maxPositiveArray == 9) {
        std::cout << "Test case 2 passed. Maximum element found correctly." << std::endl;
    } else {
        std::cout << "Test case 2 failed. Maximum element not found correctly."

{
    int largest = array[0];
    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}


/* ellipsis ... means variadic class template
   template(typename arg, typename... args)
   return_type function_name(arg var1, args... var2)
   https://www.geeksforgeeks.org/variadic-function-templates-c/
*/
template <typename F, typename ... Ts> double
Time_function(F&& f, Ts&&...args)
{
    const auto& start = std::chrono::high_resolution_clock::now();
    std::forward<F>(f)(std::forward<Ts>(args)...);
    const auto& end = std::chrono::high_resolution_clock::now();

    const auto elapsed =
            std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    return elapsed / 1000.0f;
}

void
print(int a, int b)
{
    std::cout << "a + b = " <<  a + b << std::endl;
}

void add1(int &v)
{
  v+=1;
}

void add2(int &v)
{
  v+=2;
}

template <typename F>
void doOperation(F f)
{
  int temp=0;
  f(temp);
  std::cout << "Result is " << temp << std::endl;
}

struct add3
{
    void operator() (int &v) {v+=3;}
};

int
main(int argc, char** argv)
{
    int a = 10;
    int b = 99;
    double elapsed_time = Time_function(print, a, b);

    std::cout << "elapsed_time: " << elapsed_time << "ms" << std::endl;
  doOperation(add1);
  doOperation(add2);
  doOperation(add3());
    return 0;
}
