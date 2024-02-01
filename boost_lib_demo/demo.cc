// I run the following program on a 32 cores computer:

#include<iostream>
#include<algorithm>
#include<boost/thread.hpp>
using namespace std;

boost::thread_group g;
boost::mutex _mtx;

class A{
public:
    void foo()
    {
        for(int ix = 0; ix < 10000000; ++ix)
                vec.push_back(ix);

        // sort the vector vec in descending order
        sort(vec.begin(), vec.end());



        cout << vec[0] << endl;
    }
private:
        vector<int> vec;
};

void thread_fun()
{
    A a;
    _mtx.lock();   //line 24
    a.foo();
    _mtx.unlock();  //line 26
}

int main()
{
        g.add_thread(new boost::thread(thread_fun));
        g.add_thread(new boost::thread(thread_fun)); //line 32

        g.join_all();
}
