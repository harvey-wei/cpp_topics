#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() 
{
    fs::path dir ("/tmp/");
    fs::path file ("foo.txt");
    fs::path full_path = dir / file;
    std::cout << full_path << std::endl;

    return 0;
}
