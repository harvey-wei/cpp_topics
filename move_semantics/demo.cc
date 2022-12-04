#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>


int main()
{
    std::vector<int> a = {1, 2, 3, 4};

    std::vector<std::vector<int>> res;

    /* https://blog.csdn.net/u013834525/article/details/104047635 */

    res.push_back(std::move(a));
    res.push_back(a);
    res.push_back(a);

    std::cout << "The elements after move a, its size " << a.size() << std::endl;
    for (const auto& ele: a)
    {
        std::cout << ele << std::endl;
    }

    for (int i = 0; i < res.size(); ++i)
    {
        std::cout << "row " << i << std::endl;
        for (int j = 0; j < res[i].size(); ++j)
        {
            std::cout << res[i][j] << " ";
        }

        std::cout << std::endl;
    }


    return 0;
}
