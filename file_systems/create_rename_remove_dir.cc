#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
    path p{"./Test"};
    try
    {
        if (create_directory(p))
        {
          rename(p, "./Test2");
          /* boost::filesystem::remove("../Test2"); */
        }

        std::cout << current_path() << '\n';
        /* current_path("C:\\"); */
        std::cout << current_path() << '\n';
    }
    catch (filesystem_error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

/**
 * https://theboostcpplibraries.com/boost.filesystem-files-and-directories
 */
