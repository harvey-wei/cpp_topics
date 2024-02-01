/* ref: https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/ */
/* ref: https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=msvc-170 */
/* C enum has global scope which brings about limitations */
/* C++11 has introduced enum classes (also called scoped enumerations), that makes enumerations
   both strongly typed and strongly scoped. Class enum doesn’t allow implicit conversion to int,
   and also doesn’t compare enumerators from different enumerations.
*/

// C++ program to demonstrate working
// of Enum Classes

#include <iostream>
using namespace std;

class Point
{
    public:
        /* The enum class Traversible is visible in current class */
        enum class Traversible
        {
            traversable,
            non_traversable,
            undecided
        };

        /* Anonymous enum class. */
        enum {left, right};

        float x, y;
        Traversible drivable = Traversible::traversable;
        int z = left;
};

int main()
{
	enum class Color { Red,
					Green,
					Blue };
	enum class Color2 { Red,
						Black,
						White };
	enum class People { Good,
						Bad };

	// An enum value can now be used
	// to create variables
	int Green = 10;

	// Instantiating the Enum Class
	Color x = Color::Green;

	// Comparison now is completely type-safe
	if (x == Color::Red)
		cout << "It's Red\n";
	else
		cout << "It's not Red\n";

	People p = People::Good;

	if (p == People::Bad)
		cout << "Bad people\n";
	else
		cout << "Good people\n";

	// gives an error
	// if(x == p)
	// cout<<"red is equal to good";

	// won't work as there is no
	// implicit conversion to int
	// cout<< x;

	cout << int(x);

    Point pt;
    pt.drivable = Point::Traversible::undecided;

    std::cout << "pt.drivable: " << int(pt.drivable) <<  std::endl;

	return 0;
}
