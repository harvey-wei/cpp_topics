#include <iostream>
#include <string>

using namespace std;
class MyClass{
   private:
      static int st_var;

   public:
      MyClass(){
         st_var++; //increase the value of st_var when new object is created
      }
      static int getStaticVar() {
         return st_var;
      }
      static std::string st_name;
};

/*
 * If the static class variable is not initialized outside of the class, compiler reports the error:
 * │/usr/bin/ld: demo.cc:(.text._ZN7MyClassC2Ev[_ZN7MyClassC5Ev]+0x18): undefined reference
 * to `MyClass::st_var'
 * \ref https://www.tutorialspoint.com/how-to-initialize-private-static-members-in-cplusplus
 * https://stackoverflow.com/questions/5019856/initialize-static-variables-in-c-class
 */
int MyClass::st_var = 0; //initializing the static int

/*
 * You can initialize the static class variable without assigning a value to it:
 */
std::string MyClass::st_name;

int
main() {
   MyClass ob1, ob2, ob3; //three objects are created
   cout << "Number of objects: " << MyClass::getStaticVar() << std::endl;

   std::cout << "Name: " << MyClass::st_name << std::endl;

   /* Ok not initialize the static variable */
   static int st_num;
   st_num = 10;

   std::cout << "st_num: " << st_num << std::endl;

   return 0;
}
