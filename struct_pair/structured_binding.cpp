#include <iostream>
#include <utility>  // make_pair
#include <cassert>
#include <cmath>

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


// type-deduction using auto happens at compile time which leads to no performance difference!
int main() {
    int a, b, c;

    std::cin >> a >> b >> c;

    auto [found, solutions] = quadratic(a, b, c);
    
    if (found) {
        std::cout << solutions.first  << " " << solutions.second << std::endl;
    } else {
        std::cout << "No solutioins found" << std::endl;
    }

    return 0;
}
