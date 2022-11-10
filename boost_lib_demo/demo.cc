#include <boost/shared_ptr.hpp>
#include <iostream>

int main()
{
    boost::shared_ptr<int> a(new int(10));

    std::cout << "a: " << *a << std::endl;

    return 0;
}
