#include<iostream>
using namespace std;

#define LOG(msg) errorLog( __FILE__, __FUNCTION__, __LINE__, msg )
#define LOG_NULLPTR(ptr) check_pointer(__FILE__, __FUNCTION__, __LINE__, ptr)

int
errorLog (const char* file, const char* func, const int line,  const std::string& msg){
   cerr << "[" << file << "] " << "[" << func << "]" << "[" << line << "]" << " " << msg << endl;

   return 0;
}

int
check_pointer(const char* file, const char* func, const int line, void* ptr){
   if (nullptr == ptr)
   {
       cerr << "[" << file << "] " << "[" << func << "]" << "[" << line << "]" << " " <<
           "nullptr!" << endl;
   }
   else
   {
       cout << "[" << file << "] " << "[" << func << "]" << "[" << line << "]" << " " <<
           "nonnon--nullptr!" << endl;
   }

   return 0;
}

int
main()
{
    LOG("This is a dummy error");

    int* ptr = nullptr;
    LOG_NULLPTR(ptr);

    double* ptr_db = new double(10);
    LOG_NULLPTR(ptr_db);

    return 0;
}
