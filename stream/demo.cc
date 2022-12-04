// C++ program to demonstrate
// anomaly of delimitation of
// getline() function
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void get_char(stringstream& data_stream)
{
    string curr;
    getline(data_stream, curr, ',');
    std::cout << "curr " << curr << std::endl;
}

int main()
{
	/* string name; */
	/* int id; */

	/* // Taking id as input */
	/* cout << "Please enter your id: \n"; */
	/* cin >> id; */
	/**/
	/* // Takes the empty character as input */
	/* cout << "Please enter your name: \n"; */
	/* getline(cin, name); */
	/**/
	/* // Prints id */
	/* cout << "Your id : " << id << "\n"; */
	/**/
	/* // Prints nothing in name field */
	/* // as "\n" is considered a valid string */
	/* cout << "Hello, " << name */
	/* 	<< " welcome to GfG !\n"; */
	/**/
	/* // Again Taking string as input */
	/* getline(cin, name); */
	/**/
	/* // This actually prints the name */
	/* cout << "Hello, " << name */
	/* 	<< " welcome to GfG !\n"; */

    stringstream data_stream;
    data_stream.str("1,2,3,#");
    get_char(data_stream);
    get_char(data_stream);
    get_char(data_stream);

    std::string temp = data_stream.str();
    std::cout << temp << std::endl;

    /* string curr; */
    /* getline(data_stream, curr, ','); */
    /* std::cout << "curr" << curr << std::endl; */
    /**/
    /* getline(data_stream, curr, ','); */
    /* std::cout << "curr" << curr << std::endl; */
    /**/
    /* getline(data_stream, curr, ','); */
    /* std::cout << "curr" << curr << std::endl; */

	return 0;
}
