#ifndef BASEBALLPLAYER_H
#define BASEBALLPLAYER_H
#include <iostream>
#include <string>
using namespace std;

#include "Person.h"   // inlcuding the base class declaration which is required by static language!

// BaseballPlayer class inherit publicly from Person!
class BaseballPlayer : public Person
{
	private:
		double m_battingAverage;
		int m_homeRuns;		

	public:
		// constructor
		BaseballPlayer(const string & _name, int _age,
				double _bat_avg, int _runs);

		double get_bat_avg() const;
		int get_home_runs() const;



};

#endif

