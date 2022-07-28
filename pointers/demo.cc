#include <iostream>

int main()
{
    int arr[3][4] = {{11,22,33,44},
                    {55,66,77,88},
                    {11,66,77,44}};

    int *ptr2int; // pointer to int
    int (*ptr2array)[4]; // pointer to an array of 4 integer
    int *ptr_array[4]; // an array of 4 integers

    /* The values of the following three pointers are the same.
       But the base type of them are different which means the pointer arithmetic for them is also
       different.
       Note that pointer arithmetic is performed relative to the base type size of the pointer
       arr is a pointer to a array of size 4, (*pt)[4]
    */
    std::cout << "                     The value of 2D array name: " << arr << std::endl;
    std::cout << "The value of the pointer to 0th row of 2D array: " << &(arr[0]) << std::endl;
    std::cout << "     The address of the 0th element of 2D array: " << &(arr[0][0]) << std::endl;

    /* Always remember a 2-D array is actually a 1-D array where each element is a 1-D array. */
    ptr2array = arr;
    std::cout << "The value of  ptr2array: " << ptr2array << std::endl;
    /* De-referencing a pointer to a 1D array get a pointer to element of 1D array */
    /*ptr[i] amounts to *(ptr + i)*/
    std::cout << "The value of *ptr2array: " << *ptr2array << std::endl;
    std::cout << "*(*(ptr2array)): " << *(*(ptr2array)) << std::endl;
    std::cout << "    array[0][0]: " << arr[0][0] << std::endl;

    return 0;
}

/*
   ref: https://overiq.com/c-programming-101/pointers-and-2-d-arrays/
*/
