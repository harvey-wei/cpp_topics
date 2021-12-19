#include <iostream>
#include <map>
using namespace std;

int main()
{
	// Creating a map with key and value
	// fields as String
	map<string, string> sites;
	
	sites.insert({ "GeeksforGeeks", "Coding Resources" });
	sites.insert({ "StackOverflow", "Q-A type" });
	sites.insert({ "Wikipedia", "Resources + References" });

	for (auto & [ key, value ] : sites)
	{
	cout << key.c_str() << " " << value.c_str() << endl;
	}
	
	return 0;
}

