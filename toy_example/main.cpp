#include "iostream"
using namespace std;

int main()
{
	int size(0);
	cout << "Please enter a integer" << endl;
	cin >> size;
	int arr[size];
	for(int i(0);i < size; i++)
	{
		arr[i] = i*i;
		cout << arr[i] << endl;
	}

	return 0;
}
