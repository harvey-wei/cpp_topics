#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
    path p = current_path();

    /* It points to the beginning of the directory */
    directory_iterator it{p};

    /**
     * To retrieve the end of a directory, the class must be instantiated with the default
     * constructor.
     */
    while (it != directory_iterator{})
    {
        std::cout << *(it++) << '\n';
    }
}


