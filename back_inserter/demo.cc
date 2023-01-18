// C++ program to demonstrate std::back_inserter
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// Declaring first container
	vector<int> v1 = { 1, 2, 3 };

	// Declaring second container without specifying
	// its size
	vector<int> v2;

    std::cout << "The size of v2: " << v2.size() << std::endl;
    std::cout << "The capacity of v2: " << v2.capacity() << std::endl;
    std::copy(v1.begin(), v1.end(), v2.begin()); // seg fault, v2's capacity is zero.

    v2.reserve(2);
	std::copy(v1.begin(), v1.end(), v2.begin()); // capacity == 2, OK

    std::cout << "The size of v2: " << v2.size() << std::endl;
    std::cout << "The capacity of v2: " << v2.capacity() << std::endl;
	// Using std::back_inserter inside std::copy
	std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
	/* std::copy(v1.begin(), v1.end(), v2.begin()); // seg fault, v2 has no  */
	// v2 now contains 1 2 3

	// Displaying v1 and v2
	cout << "v1 = ";

	int i;
	for (i = 0; i < 3; ++i) {
		cout << v1[i] << " ";
	}

	cout << "\nv2 = ";
	for (i = 0; i < 3; ++i) {
		cout << v2[i] << " ";
	}

	return 0;
}

/**
 * /ref https://www.geeksforgeeks.org/stdback_inserter-in-cpp/
 */
