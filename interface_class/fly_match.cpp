#include "fly_match.h"

void fly_match(Flying *f1, Flying *f2)
{
	f1->takeoff();
	f1->land();
	f2->takeoff();
	f2->land();
}
