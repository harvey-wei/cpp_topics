#include <iostream>
#include <cstdarg>

void printNumbers(int numArgs, ...) {
    va_list args;
    va_start(args, numArgs);

    for (int i = 0; i < numArgs; ++i) {
        int value = va_arg(args, int);
        std::cout << value << " ";
    }

    va_end(args);
}

int main() {
    printNumbers(3, 10, 20, 30);
    return 0;
}
