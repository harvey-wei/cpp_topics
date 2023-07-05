#include <iostream>
#include <boost/filesystem.hpp>

// https://stackoverflow.com/questions/829468/how-to-perform-boostfilesystem-copy-file-with-overwrite
int
main(int argc, char** argv)
{
    boost::filesystem::path src = boost::filesystem::system_complete("./test.txt");
    boost::filesystem::path dst = boost::filesystem::system_complete("./test_copy.txt");

    boost::filesystem::copy_file(src, dst, boost::filesystem::copy_option::overwrite_if_exists);

    return 0;
}
