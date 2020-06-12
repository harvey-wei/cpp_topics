#include "Flying.h"
#include "Plane.h"
#include "Fighter.h"
#include "fly_match.h"
/*
The following is an example of the multiple inheritance. Nevertheless, you can try multi-level inheritance!
*/

int main()
{
	// you can not instantiate the Flying and Plane which are ABC
	Fighter p1("001");
	Fighter p2("002");
	p1.print_num();
	p2.print_num();

	// Global Function!!! Scope goes across multiple files!
	// ABC and interface class are both C++ Class. Hence, all propertis of C++ Class apply to ABC and interface class!!!
	fly_match(&p1, &p2);  //The most derived class is A most base class
}
