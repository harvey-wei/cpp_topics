// Another example program to demonstrate working
// of enum in C
#include <iostream>

enum year{Jan, Feb, Mar, Apr, May, Jun, Jul,
		Aug, Sep, Oct, Nov, Dec};

int main()
{
    int i;
    for (i=Jan; i<=Dec; i++)
    {
        std::cout << i << std::endl;
    }

    /* No need to create an enum variable */
    std::cout << "Jan: " << Jan << std::endl;

    return 0;
}

