#include <iostream>
#include <vector>
#include <utility>


int
main(int argc, char** argv)
{
    std::vector<std::pair<int, int>> non_zero_locs;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            non_zero_locs.emplace_back(i, j);
        }
    }

    for (const auto& loc: non_zero_locs)
    {
        std::cout << "r = " << loc.first << ", " << "c = " << loc.second << std::endl;
    }
    return 0;
}
