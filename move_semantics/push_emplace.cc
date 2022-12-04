#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class BaseClass
{
    public:
        BaseClass(const std::string _name, int _cnt)
            : name(_name), count(_cnt)
        {
            std::cout << name << " constructor is called " << std::endl;
        }

        BaseClass(const BaseClass& b)
        {
            name = b.name;
            count = b.count;
            std::cout << name << " copy constructor is called " << std::endl;
        }

        BaseClass(BaseClass&& b)
        {
            name = b.name;
            count = b.count;
            std::cout << name << " move constructor is called " << std::endl;
        }

        ~BaseClass()
        {
            std::cout << name << " destructor is called " << std::endl;
        }

        std::string get_name()
        {
            return name;
        }

    private:
        std::string name;
        int count;
};

int main(int argc, char** argv)
{
    std::vector<BaseClass> vec_bc;
    std::vector<std::string> vec_s;
    vec_bc.reserve(20);  // reserve 10 elmemets to avoid table doubling!

    std::cout << "---------- emplace_back rvalue: " << std::endl;
    vec_bc.emplace_back(BaseClass("b1", 1)); // move constructor is called.
    std::cout << std::endl;

    std::cout << "---------- emplace_back rvalue by directly passing class params: " << std::endl;
    vec_bc.emplace_back("b1_1", 1); // move constructor is called.
    std::cout << std::endl;

    std::cout << "---------- push_back rvalue: " << std::endl;
    vec_bc.push_back(BaseClass("b2", 1));
    std::cout << std::endl;

    /* std::cout << "---------- push_back rvalue by directly passing class params: " << std::endl; */
    /* vec_bc.push_back("b1_1", 1); */  // Failed to compile.

    std::cout << "---------- emplace_back lvalue: " << std::endl;
    BaseClass b3("b3", 1);
    vec_bc.emplace_back(b3); // copy constructor is called.
    std::cout << std::endl;

    std::cout << "---------- push_back lvalue: " << std::endl;
    BaseClass b4("b4", 1);
    vec_bc.push_back(b4); // copy constructor is called.
    std::cout << std::endl;

    std::cout << "---------- emplace_back std::move rvalue: " << std::endl;
    BaseClass b5("b5", 1);
    vec_bc.emplace_back(std::move(b5)); // move constructor is called!
    /* We don't null out the input object in move constructor! */
    /* std::cout << "b5 after move: " << b5.get_name() << std::endl; */
    std::cout << std::endl;

    std::cout << "---------- push_back std::move rvalue: " << std::endl << std::endl;
    BaseClass b6("b6", 1);
    vec_bc.push_back(std::move(b6)); // move constructor is called!
    std::cout << std::endl;

    std::cout << "---------- push_back lvalue reference: " << std::endl << std::endl;
    BaseClass b7("b7", 1);
    BaseClass& ref2b7 = b7;
    vec_bc.push_back(ref2b7);


    std::cout << "----------" << std::endl;

    return 0;
}


/*
   The only difference between and push_back and emplace_back is that
   emplace_back support direct passing of parameer for creating a vector element object, in which
   case only one element object is created!

   Is the move-from obejct nulltpr?
   Depending on the definition of the move constructor. For the std::vector, std::move(vec_obj)
   nulls out the vec_obj. For the std::pair, std::move(pair_obj) does not nulls out the pair_obj.

   https://blog.csdn.net/u013834525/article/details/104047635
   当参数是左值时，push_back和emplace_back的区别在于后者对参数多进行了一个std::forward操作
   当参数是右值时，push_back其实是调用的emplace_back实现的

   What is std::forward?
   https://stackoverflow.com/questions/3582001/what-are-the-main-purposes-of-using-stdforward-and-which-problems-it-solves/3582313#3582313
   It is a conditioinal cast.
   For lvalues, just return T&. Otherwise, cast to rvalue reference and return rvalue.
   https://stackoverflow.com/questions/8526598/how-does-stdforward-work

   How is push_back different from emplace_back?
   如果参数是左值，两个调用的都是copy constructor
   如果参数是右值，两个调用的都是move constructor（C++ 11后push_back也支持右值）
   最主要的区别是，emplace_back支持in-place construction，也就是说emplace_back(10, “test”)可以
   只调用一次constructor，而push_back(MyClass(10, “test”))必须多一次构造和析构
*/
