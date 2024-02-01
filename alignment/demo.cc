#include <iostream>
#include <chrono>

struct MyStruct {
    char c;
    int i;
};

struct MyStructTwo {
    int i;    // 4 bytes
    char c1;  // 1 byte
    char c2;  // 1 byte

    // Total size: 8 bytes
};

struct MyStructThree
{
    char c1; // 1 byte
    int i; // 4 bytes
    char c2; // 1 byte

    // Total size: 12 bytes
};


int main() {
    MyStruct myStruct;

    const int max_iter = 100000000;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < max_iter; ++i) {
        myStruct.c = 'a';
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken with aligned access: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < max_iter; ++i) {
        *reinterpret_cast<char*>(&myStruct + 1) = 'a'; // Unaligned access
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Time taken with unaligned access: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds\n";



    std::cout << "Size of MyStructTwo: " << sizeof(MyStructTwo) << " bytes\n";


    return 0;
}

