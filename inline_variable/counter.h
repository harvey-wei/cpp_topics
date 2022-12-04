#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>


/*
   One translation unit (.cc and what is included) are compiled to object file (.o).
*/
inline int g_counter = 0; // inline variable is c++17 feature
/* static int g_counter = 0; // static variable and static function have internal linkage (scope) */

inline void dump()
{

    std::cout << "dump: g_counter value: " << g_counter << ", address: "
            << &g_counter << std::endl;
    ++g_counter;
}

/* Q: Normally, define a global variable in .cc and declare it by extern global_var_name.  Why not define a global variable in header file. */
/* A: It might be the case that two different .cc include the same header file where a global variable is defined. In this case, the global variable is defined twice -> compile linker error -> multiple definitions of the same variable. */


/* Where to put inline function and inline variable?
 * You should put it in the header file such that the compiler can subsitute the calling of inline
 * function by the its definition.
 *
 * So, in practical terms the (now accepted) proposal allows you to use the inline keyword to
 * define an external linkage const namespace scope variable, or any static class data member,
 * in a header file, so that the multiple definitions that result when that header is included
 * in multiple translation units are OK with the linker – it just chooses one of them.
 *
 * inline function and inline variable must be put in the header file such that multiple .cc files
 * can inlcude them. Note that linker makes these multiple cc files point the same inline variable
 * and inline function.
 * However, static variables and static functions have internal linkage (scope is limited in the cc
 * which include headers).
 * Different cc files which include these header files will make their own scope of the static variables.
 **/

/* https://zh-blog.logan.tw/2020/03/22/cxx-17-inline-variable/ */
#endif // COUNTER_H
