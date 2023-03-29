#include <boost/filesystem.hpp>
#include <iostream>

namespace fs = boost::filesystem;
int
main()
{
    fs::path p = fs::current_path();
    std::cout << "current path: " << p << std::endl;

    fs::path full_path = fs::system_complete("../file_systems/");

    std::cout << "full path to file_systems tutorial: " << full_path.string() << std::endl;

    fs::directory_iterator it(full_path);

    /* fs::directory_iterator() creates the end iterator. */
    while (fs::directory_iterator() != it)
    {
        std::cout << *(it++) << std::endl;
    }

    return 0;
}
/**
 * \ref /home/harvey/Files/tutorials/cpp_topics/file_systems/../file_systems/
 */
