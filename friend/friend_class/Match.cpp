#include "Match.h"
#include <iostream>
using namespace std;

// Besides the inheritance hierachy, when one class uses another class, initializer list is also quite helpful!


Match::Match(int _hour, int _min, int _sec): m_time_Timer(_hour, _min, _sec)
{

}

void Match::test_time()
{
	// print_time and data member of Time are private!
	// Need Friend Class
	// We can declare Match as a friend class of Time
	m_time_Timer.print_time();
	cout << m_time_Timer.m_int_hour << "Hour" << m_time_Timer.m_int_min << "Minute" <<
		m_time_Timer.m_int_sec << "Second" <<endl;

}
