// alignment_of example
#include <iostream>
#include <stdio.h>
#include <stdalign.h>

// objects of struct S can be allocated at any address
// because both S.a and S.b can be allocated at any address
struct S {
    char a; // size: 1, alignment: 1
    char b; // size: 1, alignment: 1
}; // size: 2, alignment: 1
// objects of struct X must be allocated at 4-byte boundaries
// because X.n must be allocated at 4-byte boundaries
// because int's alignment requirement is (usually) 4
struct X {
    int n;  // size: 4, alignment: 4
    char c; // size: 1, alignment: 1
    // three bytes padding
}; // size: 8, alignment: 4

int main(void)
{
    /* alignof value is the alignment requirement of the largest element in the structure. */
    /* https://stackoverflow.com/questions/11386946/whats-the-difference-between-sizeof-and-alignof */
    printf("sizeof(struct S) = %zu\n", sizeof(struct S));
    printf("alignof(struct S) = %zu\n", alignof(struct S));
    printf("sizeof(struct X) = %zu\n", sizeof(struct X));
    printf("alignof(struct X) = %zu\n", alignof(struct X));
}

/* int main() */
/* { */
/*   std::cout << "alignment_of:" << std::endl; */
/*   std::cout << "char: " << std::alignment_of<char>::value << std::endl; */
/*   std::cout << "int: " << std::alignment_of<int>::value << std::endl; */
/*   std::cout << "int[20]: " << std::alignment_of<int[20]>::value << std::endl; */
/*   std::cout << "long long int: " << std::alignment_of<long long int>::value << std::endl; */
/*   std::cout */
/**/
/*   return 0; */
/* } */


/**
 * https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
 * Wikipedia Reference:
 * https://en.wikipedia.org/wiki/Data_structure_alignment
 */
