#include <iostream>

class MyClass {
public:
    MyClass(int value) : m_value(value) {
        std::cout << "Constructor called. Value: " << m_value << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called. Value: " << m_value << std::endl;
    }

    void print() const {
        std::cout << "Value: " << m_value << std::endl;
    }

private:
    int m_value;
};

void test()
{
    // new call operator new to allocate memory and call Constructor
    MyClass* obj = new MyClass(100);

    obj->print();

    // delete call Destructor and operator delete to release memory.
    delete obj;
}

int main() {
    // Allocate memory manually by operator new and sizeof
    void* memory = operator new(sizeof(MyClass));

    // Construct an object at the given memory location
    // new(memory) is placement new
    MyClass* object = new (memory) MyClass(42);

    // Use the object
    object->print();

    // Destroy the object manually
    object->~MyClass();

    // Deallocate memory manually
    // operator delete will not call Destructor.
    operator delete(memory);

    test();

    return 0;
}

