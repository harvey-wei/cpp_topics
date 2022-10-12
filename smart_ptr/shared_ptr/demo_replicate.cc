#include <iostream>
using namespace std;


class Counter
{
    public:
        // Constructor
        Counter() : m_counter(0) {};

        // Should not be assignable and copyable.
        Counter& operator=(const Counter &other) = delete;
        Counter(const Counter &other) = delete;

        // Destructor
        ~Counter() {};

        void reset()
        {
            m_counter = 0;
        };

        unsigned int get()
        {
            return m_counter;
        }

        /* https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/ */
        // Overload prefix increment operator
        unsigned int operator++()
        {
            ++m_counter;

            return m_counter;
        }

        // pass a dummy int to indicate postfix increment
        unsigned int operator++(int)
        {
            unsigned int temp = m_counter;
            m_counter++;

            return temp;
        }

        // Overload prefix decrement operator
        unsigned int operator--()
        {
            --m_counter;

            return m_counter;
        }

        // Overload postfix decrement operator
        unsigned int operator--(int)
        {
            unsigned int temp = m_counter;
            m_counter--;

            return temp;
        }

        // Overload stream operator
        // https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
        // https://www.programiz.com/cpp-programming/friend-function-class
        // When you make something a (non-static) member function, there is an implied first
        // argument, the calling object
        // The function will be automatically targeted into the surrounding namespace, i.e. global.
        // object of ostream is on the left side of << while counter lies on the right side of <<.
        // Ref: https://stackoverflow.com/questions/476272/how-to-properly-overload-the-operator-for-an-ostream
        friend ostream& operator<<(ostream& os, const Counter &counter)
        {
            os << "Counter value: " << counter.m_counter << std::endl;

            /* return ostream for chaining << */
            return os;
        }



    private:
        unsigned int m_counter;
};


int main()
{
    return 0;
}

/**
  * Ref: https://www.geeksforgeeks.org/how-to-implement-user-defined-shared-pointers-in-c/
  *
  * Q: What is raw pointer?
  * A: returned by new operator.
  *
  * Q: Why to overload stream operator as global?
  * A: In operator overloading, if an operator is overloaded as a member, then it must be a
  *    member of the object on the left side of the operator. For example, consider the statement
  *    “ob1 + ob2” (let ob1 and ob2 be objects of two different classes). To make this statement
  *    compile, we must overload ‘+’ in a class of ‘ob1’ or make ‘+’ a global function.
  * Ref: https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
  *
  * Q: Why to use friend << ?
  * Ref: https://leimao.github.io/blog/CMake-Public-Private-Interface/
  */
