#include <boost/filesystem.hpp>
#include <iostream>

int
main(int argc, char** argv)
{
    for(auto& part : boost::filesystem::path("/tmp/child_dir/"))
    {
        std::cout << part << "\n";
    }

    /* boost::filesystem::path path("/tmp/child_dir/"); */
    /* std::cout << "child_dir: " << path.filename().string() << std::endl; */

    std::string path = "/home/person/dir";
    std::size_t botDirPos = path.find_last_of("/");
    // get directory
    std::string dir = path.substr(0, botDirPos);
    // get file
    std::string file = path.substr(botDirPos, path.length());
    // change directory.
    chdir(dir.c_str());

    return 0;
}


/**
 * \ref https://stackoverflow.com/questions/24734625/how-to-split-a-path-into-separate-strings
 * \ref
 */
