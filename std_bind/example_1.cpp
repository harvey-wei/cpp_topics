#include <iostream>


int add(int first, int second)
{
    return first + second;

}


int main()
{
    /**/
    auto add_func = std::bind(&add, std::placeholders::_1, std::placeholders::_2);  // auto is a functio object
    int res = add_func(4, 6);  // equivalent to add(4, 6)
    std::cout << res << std::endl;
    std::cout << res ;
}
