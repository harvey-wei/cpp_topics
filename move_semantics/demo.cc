// https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c

#include <iostream>

class Intvec
{
public:
    explicit Intvec(size_t num = 0)
        : m_size(num), m_data(new int[m_size])
    {
        log("constructor");
    }

    Intvec(Intvec&& source)
        : m_size(source.m_size), m_data(source.m_data)
    {
        // null out the pointer of the temporary object preventing more than one object to point to same memory location.
        source.m_data = nullptr;
    }

    ~Intvec()
    {
        log("destructor");
        if (m_data) {
            delete[] m_data;
            m_data = 0;
        }
    }

    Intvec(const Intvec& other)
        : m_size(other.m_size), m_data(new int[m_size])
    {
        log("copy constructor");
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }

    /** copy assignment operator
      * param[in] must be a constant lvalue reference which accepts both lvalue and rvalue.
      * when we don’t write our own assignment operator, the compiler creates an copy assignment operator itself that does shallow copy and thus causes problems
      * https://www.geeksforgeeks.org/default-assignment-operator-and-references-in-cpp/
      * The compiler defines the default copy constructor. If the user defines no copy constructor, compiler supplies its constructor.
      * But NO default move assignment operator and move constructor!
      * https://stackoverflow.com/questions/4819936/why-no-default-move-assignment-move-constructor
      */
    Intvec& operator=(const Intvec& other)
    {
        log("copy assignment operator");
        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }

    /** move assignment operator
      * The && syntax is the new rvalue reference. Like the move constructor.
      */
    Intvec& operator=(Intvec&& other)
    {
    log("move assignment operator");
    std::swap(m_size, other.m_size);
    std::swap(m_data, other.m_data);
    return *this;
    }

private:
    void log(const char* msg)
    {
        std::cout << "[" << this << "] " << msg << "\n";
    }

    size_t m_size;
    int* m_data;
};

int main()
{
    Intvec v1(20);
    Intvec v2;

    // Constant lvalue references can be assigned rvalues and lvalues.!
    const std::string &a = std::string();
    std::string str_b = "123";
    const std::string &c = str_b;


    std::cout << "assigning lvalue...\n";
    v2 = v1;
    std::cout << "ended assigning lvalue...\n";

    std::cout << "assigning rvalue...\n";
    v2 = Intvec(33);
    std::cout << "ended assigning rvalue...\n";

    return 0;
}
/** Q: Why is better to accept values by constant lvalue references into functions?
  * A: Non-const lvalue references cannot be assigned rvalues but must assigned a lvalue.
  * Constant lvalue references can be assigned rvalues and lvalues.!
  * which avoids unnecessary copying and construction of temporary objects.
  *
  * Q: How long does the rvalue reference live?
  * A: The reference rval_ref is bound to that temporary object.
  * Binding a reference to a temporary object causes the object to have its lifetime extended to match the reference's lifetime.
  * In other words, rvalue reference make temporary object to be persistent!
  * https://stackoverflow.com/questions/32194231/lifetime-of-rvalue-ref
  *
  * Q: Can a rvalue reference be modified?
  * A: Yes. https://stackoverflow.com/questions/12910637/modifying-the-value-of-rvalue-reference-how-does-it-work
  *
  * Q: Why not use const rvalue reference?
  * A: you can't move from const object referred by const Foo&&
  * https://stackoverflow.com/questions/4938875/do-rvalue-references-to-const-have-any-use
  * Q: What does std::move() do?
  * A: `move` simply returns an `rvalue reference to its argument`.
  */
