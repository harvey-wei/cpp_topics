#include "iostream"
#include "string"
using namespace std;

int main()
{
    string	name;   // declare a empty string


    cout << "Please enter your name: " << endl;
    /* cin  >> name; //  Note that carriage return will not received by cin; */
    getline(cin, name);
    cout << "The number of chars in name: " << name.size() << endl;
    //getline(cin, name);  // both carriage return and other string will be accepted
    /* for (char ch : name) { */
    /*     cout << ch << endl; */
    /* } */

    for (uint i = 0; i < name.size(); ++i)
    {
        cout << name[i] << std::endl;
    }


    if(name.empty())
    {
        cout << "The input is empty" <<endl;
        return 0;
    }

    if(name == "root")   // == logic operator
    {
        cout << "you are adminstrator" <<endl;
    }
    cout << "Hello" + name << endl;
    cout << "The length of your name is " << name.size() << endl; // name.size() do not return string!!!!
    cout << "The first letter of your name is " << name[0] << endl; // name[0] should be char so we do not use + to concatenate!!
    return 0;
    }
