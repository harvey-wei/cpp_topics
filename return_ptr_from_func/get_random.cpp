#include <ctime>
#include <cstdlib>   
#include "get_random.h"
// C++ programm can use existing C libraries by prefix the library name with small c but discard the extension .h
// In C++, standard library header file has no .h whereas the user-defined file need .h!!!

int * get_random()
{
	static int r[10];

	//set the seed
	srand(time(0));  // time(0) return the current calendar time!!
	
	for(int i(0); i < 10; i++)
	{
		r[i] = rand();
	}

}
