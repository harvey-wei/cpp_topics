#ifndef TIME_H
#define TIME_H
class Match;
/* #include "Match.h" */// will raise an compile-time error!
/*class Match is just a declaration to tell compiler about the existence of Match
while #include "Match.h" will include the whole class declaration of Match, where there is #include "Time.h".
Including Match.h from Time.h and Including Time.h from Match.h at the same time---> error!!!
*/

class Time 
{
	friend class Match;
	// or friend Match , depending on the compiler you are using
	public:
		Time(int _hour, int _min, int _sec);
	private:
		void print_time();
		int m_int_hour;
		int m_int_min;
		int m_int_sec;
};

#endif
