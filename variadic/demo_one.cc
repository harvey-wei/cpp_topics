#include <iostream>
#include <cstdarg>

void variadicFunction(int first_arg, ...) {
    va_list args;
    va_start(args, first_arg); // Initialize args

    int value = first_arg;
    while (value != -1) {
        value = va_arg(args, int); // Access the next argument
        std::cout << value << std::endl;
    }

    va_end(args); // Clean up
}

int main() {
    variadicFunction(1, 2, 3, 4, 5, -1); // -1 indicates end of arguments
    return 0;
}
