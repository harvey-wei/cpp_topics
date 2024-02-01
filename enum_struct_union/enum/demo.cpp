// Another example program to demonstrate working
// of enum in C
// https://www.geeksforgeeks.org/enumeration-enum-c/
// https://stackoverflow.com/questions/30047021/scope-of-enum-in-c-vs-c

#include <iostream>

enum year{Jan, Feb, Mar, Apr, May, Jun, Jul,
		Aug, Sep, Oct, Nov, Dec};

typedef enum{A = 0, B = 7, C = 10} data_10_type;

int main()
{
    int i;
    for (i=Jan; i<=Dec; i++)
    {
        std::cout << i << std::endl;
    }

    /* No need to create an enum variable */
    std::cout << "Jan: " << Jan << std::endl;

    std::cout << "size of data_10_type " << sizeof(data_10_type) << " bytes!" << std::endl;

    data_10_type s = C;
    data_10_type * s_add = &s;

    std::cout << "s: " << s_add << std::endl;

    return 0;
}

