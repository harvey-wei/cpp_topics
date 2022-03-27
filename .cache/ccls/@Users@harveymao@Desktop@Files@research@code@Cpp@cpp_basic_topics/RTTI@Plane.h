#ifndef PLANE_H
#define PLANE_H

#include  <string>
#include "Flying.h"
using namespace std;

class Plane : public Flying
{
	public:
		void carry();  // specific function (only connected with Plane Class)
		virtual void takeoff();  // One interface class can have multiple derived classes where the pure virtual functions are concretized/ implemented differently!
		virtual void land();
};

#endif
