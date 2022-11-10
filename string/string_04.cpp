#include <string>
#include <iostream>
using namespace std;


int main() {
    char ch;

    /* while (cin >> ch) { */
    /*     if (ch >= 'A' && ch <= 'Z' ) { */
    /*         cout << ch << " is an uppercase letter" << endl; */
    /*     } else if (ch >= 'a' && ch <= 'z') { */
    /*         cout << ch  << " is an lowercase letter" << endl; */
    /*     } else if (ch >= '0' && ch <= '9') { */
    /*         cout << ch << " is an digit" << endl; */
    /*     } else { */
    /*         cout << ch  << " is illegal" << endl; */
    /*     } */
    /* } */

    string str;
    str = "abcddedf";
    str[0] = 'x';

    cout << str << endl;
    cout << str.substr(1, 3) << endl;

return 0;
}
