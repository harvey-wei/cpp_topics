#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>
#include <vector>

class A
{
public:
    void print()
    {
        std::cout << "Class A print!" << std::endl;
    }
};

int main()
{
  boost::scoped_ptr<int> p{new int{1}};
  std::cout << *p << '\n';
  p.reset(new int{2});
  std::cout << *p.get() << '\n';
  p.reset();
  std::cout << std::boolalpha << static_cast<bool>(p) << '\n';

  boost::shared_ptr<std::vector<int>> a_ptr(new std::vector<int>(10, 0));

  for (const auto& num: *a_ptr)
  {
      std::cout << num << std::endl;
  }

  return 0;
}
