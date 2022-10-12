/*
Q1: What is the special propterties for friend class and friend function?
Friend Class and Friend Function can access the private and protected members in other class where the class and function are declared as friend.

Q2: Two types of friend function!
Friend Function Like friend class, a friend function can be given special grant to access private and protected members. A friend function can be:
a) A method of another class
b) A global function

*/

#include <iostream>
#include <string>
#include "Time.h"
#include "Match.h"
using namespace std;

/* void print_time(Time &t); */
int main()
{
    Time t(6, 34, 25);
    /* print_time(t); */
    Match m;
    m.print_time(t);

    return 0;
}

/* void print_time(Time &t) */
/* { */
/* 	// print_time is declared as a friend of Time Class. Hence, it can access the private data members and private functions as follows */
/* 	// t.private_data_members and t.private_member_func are legal!!!! */
/* 	cout << t.m_int_hour << ":" << t.m_int_minute << ":" << t.m_int_second << endl; */
/* } */

/**
  * https://www.programiz.com/cpp-programming/friend-function-class
  * https://www.geeksforgeeks.org/friend-class-function-cpp/
  * Q: Why to use friend?
  * A: Normally, the protected and private members are inaccessible from outside. However, the
  *    friend class and friend break this rule. A friend function can access the private and
  *    protected member of a class.
  * Ref: https://leimao.github.io/blog/CMake-Public-Private-Interface/
  * When a class is declared as a friend class,
  * all the member functions of the friend class become friend functions.
  *
  */
