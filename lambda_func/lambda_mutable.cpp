#include <iostream>
using namespace std;


int main()
{
    int x = 11;
    
    // 
    [x]() mutable {
        x = 22;
        cout << "Inside the lambda function, x = " << x << endl;
    } ();

    cout << "Outside the lambda function, x = " << x << endl;
    return 0;
}
