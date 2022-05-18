#include <algorithm>
#include <iostream>
#include <utility> // contain make_pair, pair class
#include <tuple>
#include <string>
#include <limits>
#include <cassert>
#include <cmath>
/* using namespace std; */
// You should almost always include header file for every class which you use in your program
// pair is a struct with two fields: first and second.

struct Student {
    std::string name;
    std::string state;
    int age;
};


// return a std::pair of the form <does_sol_exists, <sol1. sol2>>
std::pair<bool, std::pair<double, double>> quadratic(int a, int b, int c) {
    assert(a != 0);
    
    double delta = b * b - 4 * a * c;
    
    // if delta < 0, blank roots
    std::pair<double, double> blank;
    if (delta < 0) return std::make_pair(false, blank);

    // if delta >= 0
    std::pair<double, double> roots{(-b + std::sqrt(delta))/ (2 * a), (-b - std::sqrt(delta)) / (2 * a)};
    return std::make_pair(true, roots);
}


int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::pair<bool, std::pair<double, double>> results = quadratic(a, b, c);

    if (results.first) {
        std::cout << "roots are " << results.second.first << " " << results.second.second << std::endl;
    } else {
        std::cout << "No solutions found!" << std::endl;
    }

    
    return 0;
}
