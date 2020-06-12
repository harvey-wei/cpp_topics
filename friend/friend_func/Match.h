#ifndef MATCH_H
#define MATCH_H
class Time; //  it has been forward declared, but its definition is later in your file
/* #include "Time.h" */
/*
Class Time tells the compiler that the Time can found later on!
Time &t only need to know the existence of Time whereas void Match:print_time() need to know Match owns print_time.
Hence, for friend class member function, we need include the header file!!
*/
class Match
{
	public:
		void print_time(Time &t);   
};

#endif
