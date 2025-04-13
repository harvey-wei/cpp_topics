#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/* int size(0); */
	/* cout << "Please enter a integer" << endl; */
	/* cin >> size; */
	const int size = 10;
	int arr[size];
	for(int i(0);i < size; i++)
	{
		arr[i] = i*i;
		cout << arr[i] << endl;
	}

	int x = 10;
	int y = 11;
	int z = x * y;

	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	std::cout << "a[0]: " << a[0] << std::endl;

	x = x * 100;
	y = y * 1234;

	return 0;
}
