#include "main.h"

int main()
{
	// instantiate the BaseballPlayer from the stack!
	BaseballPlayer harvey("Harvey Mao", 26, 0.342, 32);

	// Look at the data members
	cout << "Name: " << harvey.get_name() << endl;
	cout << "Average of batting: " << harvey.get_bat_avg() << endl;
	cout << "Home_Runs: " << harvey.get_home_runs() << endl;


	return 0;
}
