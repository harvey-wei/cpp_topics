#include <iostream>
#include "get_random.h"
using namespace std;

int main()
{

int * ptr_rand_num = nullptr;
ptr_rand_num = get_random();

for (int i(0); i < 10 ; i++)
{
	cout << *ptr_rand_num <<endl;
	ptr_rand_num++ ;
}
}
