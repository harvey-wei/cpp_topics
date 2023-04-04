#include <chrono>
#include <utility>
#include <iostream>
#include <type_traits>

/* timing: https://stackoverflow.com/questions/31391914/timing-in-an-elegant-way-in-c */
/* clock: https://stackoverflow.com/questions/13263277/difference-between-stdsystem-clock-and-stdsteady-clock */
/* std::forward, https://cplusplus.com/reference/utility/forward/ */
/* variadic: https://learn.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-170 */
/* function as typename: https://stackoverflow.com/questions/1174169/function-passed-as-template-argument */

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
