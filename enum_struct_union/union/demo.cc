// https://www.cs.uic.edu/~jbell/CourseNotes/C_Programming/Structures.html
// https://www.geeksforgeeks.org/g-fact-38-anonymous-union-and-structure/
#include <stdio.h>
#include <iostream>

// Declaration of union is same as structures
union test {
	int x, y;
};

struct Scope {
    // Anonymous union without name
    // Anonymous unions/structures are also known as unnamed unions/structures as they don’t
    // have names. Since there is no names, direct objects(or variables) of them are not created
    // and we use them in nested structure or unions.
    union {
        char alpha;
        int num;
    };

    // Anonymous structure
    struct
    {
        char alpha_;
        int num_;
    };
};



int main()
{
	// A union variable t
	union test t;

	t.x = 2; // t.y also gets value 2
	printf("After making x = 2:\n x = %d, y = %d\n\n",
		t.x, t.y);

	t.y = 10; // t.x is also updated to 10
	printf("After making y = 10:\n x = %d, y = %d\n\n",
		t.x, t.y);

    struct Scope x, y;
    x.num = 65;
    y.alpha = 'A';
    // Note that members of anonymous union are accessed directly
    printf("y.alpha = %c, x.num = %d \n", y.alpha, x.num);

    x.num_ = 100;
    x.alpha_ = 'B';
    // Note that members of anonymous structure are accessed directly
    printf("x.alpha_ = %c, x.num_ = %d \n", x.alpha_, x.num_);

	return 0;
}
