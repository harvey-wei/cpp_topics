#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Hash function
struct hashFunction
{
  size_t operator()(const pair<int ,
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

int main()
{
    unordered_map<int, unordered_set<pair<int, int>, hashFunction>> pts_in_pixel;
    pts_in_pixel[0].insert(std::make_pair(0, 1));
    pts_in_pixel[0].insert(std::make_pair(1, 1));
    pts_in_pixel[1].insert(std::make_pair(2, 3));

    for (const auto &it: pts_in_pixel)
    {
        int pixel_id = it.first;
        std::cout << "pixel_id: " << pixel_id << std::endl;

        for (const auto &pt: it.second)
        {
            std::cout << "(" << pt.first << " ," << pt.second << ")" << std::endl;
        }
    }

    return 0;
}
