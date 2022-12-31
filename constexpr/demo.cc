#include <array>
#include <iostream>

int main()
{
    /* int n = 1; */
    /* std::array<int, n> a1; // error: n is not a constant expression */
    const int cn = 2;   // cn is evaluated at compile-time.
    std::array<int, cn> a2; // OK: cn is a constant expression
}

/**
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
 */
