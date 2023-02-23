#include <iostream>
#include <boost/filesystem.hpp>
/**
 * \ref https://stackoverflow.com/questions/4430780/how-can-i-extract-the-file-name-and-extension-from-a-path-in-c
 */
int
main()
{
    boost::filesystem::path p("/home/dir/dir/file.ext");
    std::cout << "filename and extension : " << p.filename() << std::endl; // file.ext
    std::cout << "filename only          : " << p.stem() << std::endl;     // file
    std::cout << "file extension         : " << p.extension() << std::endl; // .ext
}
