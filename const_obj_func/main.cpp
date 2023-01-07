#include "iostream"
#include "Coordinate.h"
#include "Line.h"
#include <vector>
using namespace std;

const int & front(vector<int>& vec) {
	// from const to const is OK
	// const in, non-const out is illegal.
	// non-const in, const out is OK.
	return vec[0];
}

void swap_element(std::vector<int>& vec, int i, int j)
{
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;

    return;
}

int main()
{
     const Line *p = new Line(1,2,3,4); // due to the constructor,() is needed/required/necessary

	/* Line *p = new Line; // is also OK!! */
	if(!p)
	{
		cout << "Allocation fails" <<endl;
	}
	p->print_info();  //() is used to call the function!!!!
	delete p;
	p = NULL; // the location to which p points has been deallocated!!!
	// When being created, the object member will be created before superobject
	// When being freed, the superobject will destroyed before object member


	cout << "pass and return reference" << endl;
	vector<int> vec = {1, 2, 3, 4};

	cout << front(vec) << endl;

    swap_element(vec, 0, 2);

    return 0;
}
