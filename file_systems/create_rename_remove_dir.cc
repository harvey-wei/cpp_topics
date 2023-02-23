#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
    path file_path{"./Test"};
    try
    {
        if (create_directory(file_path))
        {
          rename(file_path, "./Test2");
          boost::filesystem::remove("../Test2"); // remove directories
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
