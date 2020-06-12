#ifndef MATCH_H
#define MATCH_H
#include "Time.h"

class Match
{
	public:
		Match(int _hour, int _min, int _sec);
		void test_time();
	private:
		Time m_time_Timer;		
};

#endif
