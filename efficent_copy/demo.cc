// C++ code to demonstrate the working of copy()
// and copy_n()

#include<iostream>
#include<algorithm> // for copy() and copy_n()
#include<vector>
using namespace std;

int main()
{
    // initializing source vector
    vector<int> v1 = { 1, 5, 7, 3, 8, 3 };

    // declaring destination vectors
    vector<int> v2(6);
    vector<int> v3(6);

    // using copy() to copy 1st 3 elements
    copy(v1.begin(), v1.begin()+3, v2.begin());

    // printing new vector
    cout << "The new vector elements entered using copy() : ";
    for(int i=0; i<v2.size(); i++)
    cout << v2[i] << " ";

    cout << endl;

    // using copy_n() to copy 1st 4 elements
    copy_n(v1.begin(), 4, v3.begin());

    // printing new vector
    cout << "The new vector elements entered using copy_n() : ";
    for(int i=0; i<v3.size(); i++)
    cout << v3[i] << " ";

}

/*
   ref: https://www.geeksforgeeks.org/different-methods-copy-c-stl-stdcopy-copy_n-copy_if-copy_backward/
   ref: https://stackoverflow.com/questions/34134074/c-size-of-two-dimensional-array
   ref: https://stackoverflow.com/questions/4544804/in-what-cases-should-i-use-memcpy-over-standard-operators-in-c
*/

