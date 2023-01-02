#include <iostream>
#include <vector>


// A generic sort function
template <class T>
void sort(std::vector<T>, int size)
{
    // code to implement Quick Sort
    std::cout << "quick sort template" << std::endl;
}

// Template Specialization: A function
// specialized for char data type
// put nothing in the <> of template
// put <type name> immediately after function name
template <>
void sort<char>(std::vector<char>, int size)
{
    // code to implement counting sort
    std::cout << "sort Specialization for char data type" << std::endl;
}

template<class T>
class Test
{
    public:
        Test()
        {
            std::cout << "Generic template instance" << std::endl;
        }
};

// class template specialization
// put nothing in the <> of template
// put <type name> immediately after class name
template<>
class Test<int>
{
    public:
        Test()
        {
            std::cout << "Speicialized template for int type" << std::endl;
        }
};

/**
 * \topic Partial specialization of template.
 * \note Partial specialization of a function template, whether it is member function template or
 *       stand-alone function template, is not allowed by the Standard.
 *       But you can partially specialize the class template itself.
 * \ref https://stackoverflow.com/questions/6138439/understanding-simple-c-partial-template-specialization
 */

/* primary template */
template<class A, typename B>
class Thing
{

};

template<class A>
class Thing<A, int> /* partial specialization of the class template. */
{
    int do_something();
};

template<class A>
int Thing<A, int>::do_something()
{
    std::cout << "Partial specialization Thing<A, int>" << std::endl;
}

/**
 * \note The primary version handles all the cases where T is not a pointer!
 */
template <typename T>
struct is_pointer
{
    static const bool value = false;
};

/**
 * \note A partial specialization handles all the cases where T is a pointer.
 */
template <typename T>
struct is_pointer<T*>
{
    static const bool value = true;
};

/* The default template. */
template <typename T>
struct remove_bounds
{
    typedef T type;
};

/**
 * \note the number of template parameters in a partial specialisation does not have to match the
 *       number in the default template.
 *       However, the number of parameters that appear after the class name do have to match the
 *       number and type of the parameters in the default template.
 */
template <typename T, std::size_t N>  /* The number of template parameters does not match the
                                         default template. */
struct remove_bounds<T[N]> /* But the number of parameters after class name equals the number and
                              type of the parameters in the default template. */
{
    typedef T type;
};

int main()
{
    std::vector<int> int_vec = {1, 2, 3, 4, 5};
    std::vector<char> char_vec = {'a', 'b', 'c'};

    sort<int>(int_vec, int_vec.size());
    sort<char>(char_vec, char_vec.size());

    Test<char> t_char;
    Test<int> t_int;

    return 0;
}


/*
    Q: How does template specialization work?
    When we write any template based function or class, compiler creates a copy of that
    function/class whenever compiler sees that being used for a new data type or new set of data
    types(in case of multiple template arguments).
    If a specialized version is present, compiler first checks with the specialized version and then
    the main template. Compiler first checks with the most specialized version by matching the passed
    parameter with the data type(s) specified in a specialized version.

    https://www.geeksforgeeks.org/template-specialization-c/
*/
