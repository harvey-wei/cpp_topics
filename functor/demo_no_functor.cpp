#include <iostream>
#include <algorithm>    // std::transform
using namespace std;

int increment(int x)
{
  return x + 1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Apply increment to all elements of arr[]
  // Store the results back in arr[]
  // Note: Transform requires a unary function
  // (Only takes one argument)
  transform(arr, arr+n, arr, increment);

  for(int i(0); i < n; i++)
  {
    cout << arr[i] << endl;
  }

  return 0;
}
