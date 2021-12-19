#include "BaseballPlayer.h"

// default values can be specified only once, either in the declaration or definition!!!!
// initializer list must occur in the definition!!!!!
BaseballPlayer::BaseballPlayer(const string & _name = "", int _age = 0,
				double _bat_avg = 0.0, int _runs = 0)
 :Person(_name, _age),  //  call the Person constructor to initialize these fields by the parent class name!
m_battingAverage(_bat_avg), m_homeRuns(_runs)
{
	cout << "BaseballPlayer" <<endl;
}

double BaseballPlayer::get_bat_avg() const
{
	return m_battingAverage;
}


int BaseballPlayer::get_home_runs() const
{
	return m_homeRuns;
}
	
