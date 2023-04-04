#include <vector>
#include <unordered_set>
#include <iostream>

/**
 * \ref https://en.cppreference.com/w/cpp/algorithm/copy
 * \ref https://en.cppreference.com/w/cpp/iterator/back_insert_iterator
 */
int main()
{
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {10, 20, 30, 40, 50};

    /* Since unordered_set has push_back member function, std::back_inserter can not work on it. */
    std::unordered_set<int> num_set;
    std::copy(vec1.begin(), vec1.end(), std::inserter(num_set, num_set.end()));
    std::copy(vec2.begin(), vec2.end(), std::inserter(num_set, num_set.end()));

    /* num_vec must be reserved! Otherwise, it gives rise to errors! */
    /* std::copy(vec1.begin(), vec1.end(), num_vec.end()); */
    /* std::copy(vec2.begin(), vec2.end(), num_vec.end()); */

    /* std::back_inserter will invoke the member function push_back of std::vector. */
    std::vector<int> num_vec;
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(num_vec));
    std::copy(vec2.begin(), vec2.end(), std::back_inserter(num_vec));

    for (const auto& num: num_set)
    {
        std::cout << num << std::endl;
    }

    return 0;
}
