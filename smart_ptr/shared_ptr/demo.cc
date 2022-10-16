#include <iostream>
#include <string>
#include <sstream>
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

template<class T>
class Shared_Point
{
    public:
        // Constructor receive raw pointer returned by new operator
        // Note only be used one time.
        explicit Shared_Point(T * ptr = nullptr)
            :m_ptr(ptr), m_ref_cnt(new Counter())
        {
            if (nullptr != m_ptr) ++(*m_ref_cnt);
        }

        // Copy Constructor which can be used multiple times.
        Shared_Point(const Shared_Point<T> &obj)
        {
            m_ptr = obj.m_ptr;
            m_ref_cnt = obj.m_ref_cnt;
            ++(*m_ref_cnt);
        }

        // Get the current reference count
        unsigned int get_ref_cnt()
        {
            return m_ref_cnt->get();
        }

        // Get the pointer
        T* get_ptr()
        {
            return m_ptr;
        }

        // Recall that smart pointer should also overload dereferencing and arrow operator.
        // Overload * to return the reference to the object
        T& operator*()
        {
            return *m_ptr;
        }

        // Overload -> to return the reference to const pointer to the object
        T* const & operator->()
        {
            return m_ptr;
        }

        // Caveat: dot operator is unable to be overloaded.

        // Destructor. Free up the resource pointed to by m_ptr if reference cnt reaches zero.
        ~Shared_Point()
        {
            --(*m_ref_cnt);

            cout << "The shared pointer is released!" << endl;

            if (0 == m_ref_cnt->get())
            {
                delete m_ptr;

                // Don't forget to release the memory of the reference counter.
                delete m_ref_cnt;
                cout << "The raw pointer contained in shared pointer is deleted!" << endl;
            }
        }


    private:
        // m_ptr stores the raw pointer which is shared by multiple Shared_Point.
        T * m_ptr;

        // Record how many Shared_Point objects is the raw pointer shared by.
        Counter * m_ref_cnt;

    // Overload stream insertion operator << as a global function whose left hand operand
    // is ostream &os and right hand operand is the second argument, namely ptr.
    // Usage: cout << shared_ptr objcet
    friend ostream & operator<<(ostream &os, Shared_Point<T> &ptr)
    {
        os << "Address pointed: " <<  ptr.get_ptr() << std::endl;
        os << "Reference Count: " << ptr.get_ref_cnt() << std::endl;

        return os;
    }
};


/* The first argument time is the left hand operand of + while the second argument is the right
 * hand operand of +.
 * Hence, string + int gives rise to error!
 **/
string operator+(int time, string suf)
{
    stringstream ss;
    ss << time << suf;

    return ss.str();
}

int main()
{
    int hour = 9;
    string suffix = "p.m.";

    string time = hour + suffix;
    /* string time_ = suffix + hour;  // Error!*/

    cout << time << endl;


    // new return an universal pointer and then implicitly type-cast!
    Shared_Point<int> ptr_one(new int(132));
    *ptr_one = 100;
    cout << ptr_one;


    // Invoke the copy constructor to pointer to what ptr_one points to!
    // Hence, the raw pointer is shared by ptr_one and ptr_two.
    Shared_Point<int> ptr_two(ptr_one);
    *ptr_two = 200;
    cout << ptr_two;

    cout << "ptr_two's object is " << *ptr_two << endl;


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
  * Ref: https://www.freecodecamp.org/news/how-to-overload-operators-in-cplusplus/
  *
  * Q: Why to use friend << ?
  * Ref: https://leimao.github.io/blog/CMake-Public-Private-Interface/
  *
  * Q: For overloaded binary operators, which argument is the left hand side and which is the right
  * hand side operand?
  * Ref: https://ee.usc.edu/~redekopp/cs104/slides/L08a_OperatorOverloading.pdf
  */
