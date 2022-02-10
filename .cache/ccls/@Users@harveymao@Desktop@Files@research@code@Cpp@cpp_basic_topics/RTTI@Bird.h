#ifndef BIRD_H
#define BIRD_H

#include "Flying.h"
#include <string>
using namespace std;

class Bird : public Flying
{
	public:
		void foraging();
		virtual void land(); // concretizing the pure virtual function
		virtual void takeoff(); // conretizing the pure virtual function 
};

#endif
