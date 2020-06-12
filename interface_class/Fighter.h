#ifndef FIGHTER_H
#define FIGHTER_H
#include "Plane.h"
#include "Flying.h"
/*
class: Fighter derived from Plane Class Type
member function: Constructor takeoff and land 
*/
// Multiple Inheritance, It is also possible for the case that one interface class and one regular concrete class!
class Fighter : public Plane, public Flying
{
	public:
	Fighter(string _num = "101");
	virtual void takeoff();   // be concretized 
	virtual void land();      // be concretized
	// Though, take off and land have been concretized in Plane class
	// You can also redefine them, function overriding!

	/*
	As a side note, even if the pure virtual function has been implemented(concretized) in the Plane, you can still override the function with the same prototype by redefining it in the Fighter Class!
	Hence, pure virtual function is converted to virtual function by implementing n the derived class. The newly concretized virtual function can be inherited by the subsequent derived class. Hence, you can override the concretized virtual function for the purpose of polymorphism!
	*/
};
#endif
