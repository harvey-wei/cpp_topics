// unique_lock example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

std::mutex mtx;           // mutex for critical section

// https://cplusplus.com/reference/mutex/unique_lock/
// https://theboostcpplibraries.com/boost.thread-synchronization

void print_block(int n, char c)
{
  // critical section (exclusive access to std::cout signaled by lifetime of lck):
  std::unique_lock<std::mutex> lck (mtx);  // constructor of unique_lock get control of the mutex
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  // destructor of unique_lock release the mutex
}

int main ()
{
    // Possible output (order of lines may vary, but characters are never mixed):
    // Spawn thread calling funtion with argument values.
    std::thread th1(print_block, 50, '*'); // 50 for n, '*' for c
    std::thread th2(print_block, 50, '$');

    // https://stackoverflow.com/questions/15148057/what-does-stdthread-join-do
    // th1 and th2 joins to main(). As a result, main() will wait for th1 and th2 to complete.
    th1.join();
    th2.join();

    return 0;
}
