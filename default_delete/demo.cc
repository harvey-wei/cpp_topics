#include <iostream>
#include <array>
#include <iterator>

template<typename coord_type, size_t dimension>
struct Point
{
    Point() = default; // The default constructor is explicitly stated and

    Point(std::initializer_list<coord_type> list)
    {
        std::copy(list.begin(), list.size(), point.begin());
    }

    Point(const Point<coord_type, dimension>& other)
    {
        std::copy(other.point.begin(), other.point.size(), point.begin());
    }

    const Point<coord_type, dimension>& operator=(const Point<coord_type, dimension>& other) =
            delete;  // disable assignment operator on Point class instance.



    std::array<coord_type, dimension> point;
};


/**
 * This is useful for preventing implicit type conversions.
 * The = delete specifier can be used to prohibit calling a function with particular parameter types.
 */
void noInt(double i)
{
    std::cout << "double" << i << std::endl;
}

void noInt(int) = delete;

int main()
{
    noInt(1);
    return 0;
}

/**
 * Q: Why to use default or delete keyword?
 * A: With the introduction of move constructors and move assignment operators, the rules
 *    for when automatic versions of constructors, destructors and assignment operators are generated
 *    has become quite complex.
 *    Using = default and = delete makes things easier as you don't need to remember the rules:
 *    you just say what you want to happen.
 * Ref: https://stackoverflow.com/questions/6502828/what-does-default-mean-after-a-class-function-declaration
 *      https://en.wikipedia.org/wiki/C%2B%2B11#Explicitly_defaulted_special_member_functions
 */
