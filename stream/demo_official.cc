#include <string>
#include <iostream>
#include <sstream>

int main()
{
    // greet the user
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << ", nice to meet you.\n";

    // read file line by line
    // https://cplusplus.com/reference/sstream/stringstream/str/
    // stringstream.str() converts stringstream to string object
    // stringstream.str("xxx") set the content of stringstream to "xxx";
    // In other words, stringstream.str() realizes the convertion between stringstream and string.
    std::stringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    for (std::string line; std::getline(input, line); )
        sum += std::stoi(line);
    std::cout << "\nThe sum is " << sum << ".\n\n";

    // use separator to read parts of the line
    std::istringstream input2;
    input2.str("a;b;c;d");
    for (std::string line; std::getline(input2, line, ';'); )
        std::cout << line << '\n';

    return 0;
}
