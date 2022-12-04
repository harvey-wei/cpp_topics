#include <sstream>
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream


int main_()
{
    char str[256];

    std::cout << "Enter the name of an existing text file: ";
    std::cin.get (str, 256);    // get c-string

    std::ifstream is(str);     // open file

    char c;
    while (is.get(c))          // loop getting single characters
    std::cout << c;

    is.close();                // close file

    /* std::char_traits<char>::eof();
       https://cplusplus.com/reference/string/char_traits/eof/
       Traits::eof()
    */
    /* Traits::eof(); */

    return 0;
}

/*
https://cplusplus.com/reference/istream/istream/get/

*/

/* In C++, this macro corresponds to the value of char_traits<char>::eof(). */
#include <sstream>
#include <iostream>

int main()
{
    std::istringstream s1("Hello, world.");
    char c1 = s1.get(); // reads 'H'
    std::cout << "after reading " << c1 << ", gcount() == " <<  s1.gcount() << '\n';
    char c2;
    s1.get(c2);         // reads 'e'
    char str[5];
    s1.get(str, 5);     // reads "llo,"
    std::cout << "after reading " << str << ", gcount() == " <<  s1.gcount() << '\n';
    std::cout << c1 << c2 << str;
    s1.get(*std::cout.rdbuf()); // reads the rest, not including '\n'
    std::cout << "\nAfter the last get(), gcount() == " << s1.gcount() << '\n';
}
