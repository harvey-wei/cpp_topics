// https://stackoverflow.com/questions/5257509/freopen-equivalent-for-c-streams
// cin and cout are associated with stdin stdout in cstdio
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // redirect stdin / cin to input.txt
    // if the file is NULL, undefiend behavior
    // if the file is valid, reading from start
    //freopen("input.txt", "r", stdin);

    // redirect stdou / cout to output.txt
    // if the file is null, create new file
    // if the file is valid, delete all data in that file
//    freopen("output.txt", "w", stdout);
//    cin.ignore();
//    cin.clear();//重置错误输入
//    cin.sync();//清空缓冲区
    cout << "please enter" << endl;
    
    int a, b;
    while (cin >> a) {
        cin >> b;
        cout << a << " + " << b << " = " << a + b << endl;
    }
}
