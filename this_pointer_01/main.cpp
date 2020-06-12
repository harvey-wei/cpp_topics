#include "main.h"
using namespace std;

int main()
{
	Array arr1(10);
	arr1.print_info().set_len(5);
	cout << "len = " << arr1.get_len() <<endl;
}
