// policyComposition.cpp

#include <iostream>
#include <fstream>
#include <string>

/**
 * The class Message has the template parameter OutputPolicy (line 1) as policy.
 * \ref https://www.modernescpp.com/index.php/policy-and-traits
 */
template <typename OutputPolicy>                    // (1)
class Message {
 public:
    void write(const std::string& mess) const {
        outPolicy.print(mess);                      // (2)
    }
 private:
    OutputPolicy outPolicy;
};

/* policy one */
class WriteToCout {                                 // (5)
 public:
    void print(const std::string& message) const {
        std::cout << message << '\n';
    }
};

/* policy two */
class WriteToFile {                                 // (6)
 public:
    void print(const std::string& message) const {
        std::ofstream myFile;
        myFile.open("policyComposition.txt");
        myFile << message << '\n';
    }
};


int main() {

    Message<WriteToCout> messageCout;              // (3)
    messageCout.write("Hello world");

    Message<WriteToFile> messageFile;              // (4)
    messageFile.write("Hello world");
}

/**
  * https://blog.andreiavram.ro/cpp-policy-based-design/
  */
