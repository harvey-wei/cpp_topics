#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	// Holding digit: 3, 4, 8, 4 within vector
	vector<int> vec;  // can be resized automatically
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(4);

	// traverse the vector by indexing or iterator
	vector<int>:: iterator iter_vec(vec.begin());
	for(; iter_vec != vec.end(); iter_vec ++)
	{
		cout << *iter_vec << endl;	
	}

	// Map  
	map<string, string> m;
	pair<string, string> p1("S", "Shang Hai");
	pair<string, string> p2("B", "Bei Jing");
	pair<string, string> p3("G", "Guang Zhou");
	m.insert(p1);
	m.insert(p2);
	m.insert(p3);

	// traverse the map by key or iterators
	map<string, string>::iterator iter_map(m.begin());
	for(;iter_map != m.end(); iter_map ++)
	{
		cout << iter_map -> first << ", " << iter_map -> second	<< endl;
	}

	return 0;
}
