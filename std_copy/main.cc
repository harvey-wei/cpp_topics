#include <vector>
#include <unordered_set>
#include <iostream>

int main()
{
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {10, 20, 30, 40, 50};

    std::unordered_set<int> num_set;
    std::copy(vec1.begin(), vec1.end(), std::inserter(num_set, num_set.end()));
    std::copy(vec2.begin(), vec2.end(), std::inserter(num_set, num_set.end()));

    for (const auto& num: num_set)
    {
        std::cout << num << std::endl;
    }

    return 0;
}
