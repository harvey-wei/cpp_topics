#include <iostream>
using namespace std;

class Watch;  // forward declaration , defintion can be found later in the code!!!
/*
   Class Name: Time
   Data Members: m_int_hour, m_int_min, m_int_sec
   Member func: constructor
   Friend Class: Watch  only need forward declaration!
*/

class Time
{
	friend Watch;   // or friend class Watch
	public:
		Time(int _hour, int _min, int _sec)	
		{
			m_int_hour = _hour;
			m_int_min = _min;
			m_int_sec = _sec;
		}
	
	private:
		int m_int_hour, m_int_min, m_int_sec;
};

/*
	Class Name: Watch
	Data Members: m_time_time
	Member function: constructor and display
*/
class Watch
{
	public:
		// constructor with initializer list!
		Watch(Time _time) : m_time_time(_time.m_int_hour, _time.m_int_min, _time.m_int_sec)
		{
		}

		void display()
		{
			cout << m_time_time.m_int_hour << ":"
				<< m_time_time.m_int_min << ":"
				<< m_time_time.m_int_sec << endl;
		}

	private:
		Time m_time_time;
};

int main()
{
	Time t(6, 30, 20);
	Watch w(t);
	w.display();

	return 0;
}
