#include <iostream>
#include <fstream>

// ref: https://stackoverflow.com/questions/584868/rerouting-stdin-and-stdout-from-c
// https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-freopen-redirect-open-file

int
main(int argc, char** argv)
{
    /* redirect stdin to the specific file. */
    freopen("./num.txt", "r", stdin);

    /* redirect */
    freopen("./num_out.txt", "w", stdout);

    int num;

    std::cin >> num;
    std::cout << num << std::endl;

    std::cin >> num;
    std::cout << num << std::endl;

    std::cin >> num;
    std::cout << num << std::endl;

    std::cin >> num;
    std::cout << num << std::endl;

    return 0;
}
