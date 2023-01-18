#include <boost/filesystem/fstream.hpp> // to make std::fstream accept boost path
#include <iostream>

using namespace boost::filesystem;

int main()
{
  path p{"test.txt"};
  ofstream ofs{p};

  ofs << "Hello, world!\n";
}

/**
 * std::fstream do not accept parameters of type boost::filesystem::path.
 * If you want to open file streams with objects of type boost::filesystem::path,
 * include the header file boost/filesystem/fstream.hpp.
 */
