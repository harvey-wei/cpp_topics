#include <iostream>
#include "Time.h"
using namespace std;


Time::Time(int _hour, int _min, int _sec)
{
	m_int_hour = _hour;
	m_int_min = _min;
	m_int_sec = _sec;
}

void Time::print_time()
{
	cout << m_int_hour << ":" << m_int_min << ":" << m_int_sec << endl;
}


