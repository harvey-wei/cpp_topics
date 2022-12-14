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
