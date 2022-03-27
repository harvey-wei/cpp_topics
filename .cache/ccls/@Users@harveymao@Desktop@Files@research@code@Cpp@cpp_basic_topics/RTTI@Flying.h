#ifndef FLYING_H
#define FLYING_H
// Interface Class 
class Flying
{
	public:
		virtual void land() = 0; // pure virtual function!
		virtual void takeoff() = 0;
};

#endif
