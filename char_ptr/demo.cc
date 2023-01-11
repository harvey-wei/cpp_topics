#include <iostream>
using namespace std;

int
main(int argc, char **argv)
{
    /* str_ptr stores the address of read-only literal */
    const char * str_ptr = "String literal"; // const is a must
    cout << "str_ptr: " << str_ptr << endl;

    /* str is a MUTABLE char array initialized by literal string*/
    char str[] = "String literal 2";

    cout << "str: " << str << endl;

    /* Modify the first element of array str */
    str[0] = 'A';

    int n = sizeof(str) / sizeof(str[0]);
    /* for (int i = 0; i < n; i++) */
    /* { */
    /*     cout << str[i] << endl; */
    /* } */

}

 /*  Q: What is meant by char*? */
 /*  A: 1. point to a constant string or character arrays */
 /*     2. char* can also be a pointer to the 0 (first) place of an array of characters. */
 /*        It was used frequently in C, where the use of String is not supported. */
