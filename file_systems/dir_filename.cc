#include <iostream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main ()
{
    fs::path dir ("/tmp");
    fs::path file ("foo.txt");
    fs::path full_path = dir / file;

    std::cout << full_path << std::endl;
    return 0;
}
