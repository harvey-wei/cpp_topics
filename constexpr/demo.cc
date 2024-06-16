// C++ program to demonstrate constexpr function to evaluate
// the size of array at compile time.
#include <iostream>
#include <array>

/* Const non-integral variables are always runtime constants (even if they have a constant expression initializer). */
/* If you need such variables to be compile-time constants, define them as constexpr variables instead (see lesson 5.5 -- Constexpr variables). */

// const double is still runtime constants.
constexpr double PI = 3.14159265359; //  Evaluate at compile time

constexpr double ConvertDegreeToRadian(const double& dDegree)
{
    return (dDegree * (PI / 180));
}


constexpr int product(int x, int y) { return (x * y); }


// A class with constexpr
// constructor and function
class Rectangle
{
    int _h, _w;
	public:
		// A constexpr constructor
		constexpr Rectangle(int h, int w) : _h(h), _w(w) {}

		constexpr int getArea() const { return _h * _w; }
};

/* https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/ */
int main()
{
    /* int n = 1; */
    /* std::array<int, n> a1; // error: n is not a constant expression */
    const int cn = 2;   // const integer  is evaluated at compile-time.
    std::array<int, cn> a2; // OK: cn is a constant expression

	// constexpr function is implicitly inlined and computed at compile time.
    int arr[product(2, 3)] = {1, 2, 3, 4, 5, 6};
    std::cout << arr[5];


    // Below object is initialized at compile time
	constexpr Rectangle obj(10, 20);
	std::cout << obj.getArea() << std::endl;

    return 0;
}


/**
 * keyword constexpr is a used to improve peformance by doing computations at compile time instead
 * of run-time.
 *
 * What is constant expression?
 * A constant expression is an expression that can be evaluated at compile time.
 * Constants of integral or enumerated type are required in several different situations,
 * such as array bounds, enumerator values, and case labels. Null pointer constants are a special
 * case of integral constants.
 *
 * ref: https://en.cppreference.com/w/cpp/named_req/LiteralType
 * A constexpr variable must be initialized at compile time. All constexpr variables are const.
 *
 * When will the constexpr function is evaluated at compile-time?
 * 1. a function must have a constexpr return type and not call any non-constexpr functions.
 * 2. a call to the function must have constexpr arguments (e.g. constexpr variables or literals).
 *
 * Why are constexpr functions are implicitly inline?
 * ref: https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions/
 *
 */
