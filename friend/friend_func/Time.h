#ifndef TIME_H
#define TIME_H
#include "Match.h"
/* class Match; */
/*
Q1:What is forward declartion?
class A means that it has been forward declared, but its definition is later in your file.(may raise an error when it is an incomplete definition!)

Q2:For Class A(Forward declaration) and include A.h when to use whom?
Rule: Use forward declaration when possible so as to avoid incomplete definition!
1. B only uses references or pointers to A. Use forward declaration then you don't need to include <A.h>. This will in turn speed a little bit the compilation.
class A ;

class B
{
  private:
    A* fPtrA ;
  public:
    void mymethod(const& A) const ;
} ;
friend class A only needs forward declaration!!!!

2. B derives from A or B explicitely (or implicitely) uses objects of class A. You then need to include <A.h>
#include <A.h>

class B : public A
{
};

class C
{
  private:
    A fA ;
  public:
    void mymethod(A par) ;
}
	Declaration of friend function need #include <A.h>!!!!!!
Refer to the post at https://stackoverflow.com/questions/9119236/c-class-forward-declaration
*/

class Time
{
	public:
		// Constructor
		Time(int _hour, int _minute, int _second);
	private:
		int m_int_hour;
		int m_int_minute;
		int m_int_second;


	friend void Match::print_time(Time &t);   // need definition of Match so include!!!
	// Friend can be put anywhere!!!!
	/* friend void print_time(Time &t); global function as friend*/
};

#endif
