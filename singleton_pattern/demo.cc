#include <iostream>
#include <string>
#include <thread>
#include <pthread.h>

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 * Two ways to implement singleton pattern.
 * https://stackoverflow.com/questions/13047526/difference-between-singleton-implemention-using-pointer-and-using-static-object
 */

class Singleton
{

protected:
    Singleton(const std::string value): value_(value)
    {
    }

    std::string value_;

public:
    /**
     * Singletons should not be cloneable.
     * delete the copy constructor.
     * https://stackoverflow.com/questions/5513881/meaning-of-delete-after-function-declaration
     * delete means prohibiting!
     */
    Singleton(const Singleton &other) = delete;

    /**
     * Singletons should not be assignable.
     * Return void or reference to class object?
     * https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
     */
    void operator=(const Singleton &) = delete;
    /* Singleton& operator=(const Singleton &) = delete; */

    static Singleton & GetInstance(const std::string& value);

    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */
    void SomeBusinessLogic()
    {
        // ...
    }

    std::string value() const{
        return value_;
    }
};


/**
 * Static methods should be defined outside the class.
 */
Singleton &Singleton::GetInstance(const std::string& value)
{
    /**
      * The statement `static Singleton inst(value);`
      * means the first time the function is called this variable will be initialized and unlike
      * non-static variables it will not be destroyed once the function ends. So when you call it
      * again it will still exist so the only instruction that will be executed the 2nd
      * (3rd, 4th, ...) time is return inst.
      */
    static Singleton inst(value);

    return inst;
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton &singleton = Singleton::GetInstance("FOO");
    std::cout << singleton.value() << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton &singleton = Singleton::GetInstance("BAR");
    std::cout << singleton.value() << "\n";
}


int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";
    /* std::thread t1(ThreadFoo); */
    /* std::thread t2(ThreadBar); */
    /* t1.join(); */
    /* t2.join(); */
    Singleton &singleton = Singleton::GetInstance("DDD");
    std::cout << singleton.value() << "\n";
    Singleton &singleton_two = Singleton::GetInstance("AAA");
    std::cout << singleton_two.value() << "\n";

    return 0;
}

