#include "Match.h"
#include <iostream>
using namespace std;
/* class Time; */
#include "Time.h"

void Match::print_time(Time &t)
{
	cout << t.m_int_hour << ":" << t.m_int_minute << ":" << t.m_int_second << endl;
}
