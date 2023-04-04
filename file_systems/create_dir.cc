#include <iostream>
#include <boost/filesystem.hpp>

void
create_dir(const std::string& dir)
{
    /* Delete the non-empty directory with the same name as the one you want to create. */
    if (boost::filesystem::exists(dir) && boost::filesystem::is_directory(dir)
            && !boost::filesystem::is_empty(dir))
    {
        boost::filesystem::remove_all(dir);
    }

    boost::filesystem::create_directory(dir);
    return;
}

int
main(int argc, char** argv)
{
    std::string dir_name = "test_dir";
    create_dir(dir_name);

    return 0;
}
