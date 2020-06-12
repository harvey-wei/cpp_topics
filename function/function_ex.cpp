#include "iostream"
using namespace std;
// Function: Return the maximum of an array
// arr: an array of integers
// count:  size of an array

// Function Declaration
int get_max(int *p, int count);
int get_max(int x, int y);

int main(){
	int arr[3] = {3, 8, 6};
	
	cout << " The maximum of the two numbers"<<endl;
	cout << get_max(arr[0],arr[2]) << endl;
	cout << " The maximum of the array" << endl;
	cout << get_max(arr, 3) << endl;


return 0;
}

// Overloaded function
// return the maximum of two integers
int get_max(int x, int y)
{
	return x > y ? x: y;
}

int get_max(int *p, int count)
{
	int max(*p);
	for(int i(1); i < count ; i ++)
	{
		if (*(p+i) > max)
		{
			max = *(p + i );
		}
	}
	return max;
}
