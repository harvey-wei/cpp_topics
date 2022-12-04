#include <unordered_set>
#include <iostream>
#include <set>
#include <vector>
#include <stack>

int main()
{
    std::pair<int, int> curr_pos(10, 10);
    std::set<std::pair<int, int>> pos_set;
    std::vector<std::pair<int, int>> vec_pairs;
    pos_set.insert(std::move(curr_pos));
    std::stack<std::pair<int, int>> stack;
    stack.push(std::move(curr_pos));
    vec_pairs.push_back(std::move(curr_pos));

    std::vector<int> vec = {0, 1, 2, 3, 4};
    std::vector<std::vector<int>> vec_of_vecs;
    vec_of_vecs.push_back(std::move(vec));

    std::cout << "The size of vec after being moved: " << vec.size() << std::endl;
    std::cout << curr_pos.first << ", " << curr_pos.second << std::endl;

    std::tuple<int, int, int> curr_pose;
    std::get<0>(curr_pose) = 11;
    std::get<1>(curr_pose) = 12;
    std::get<2>(curr_pose) = 13;

    std::vector<std::tuple<int, int, int>> vec_triplets;
    vec_triplets.push_back(std::move(curr_pose));
    vec_triplets.push_back(std::move(curr_pose));

    std::cout << "The triplet after being moved: " << std::get<0>(curr_pose) << ", " <<
            std::get<1>(curr_pose) << ", " << std::get<2>(curr_pose) << std::endl;
}


/*
   Q: Is a moved-from vector always empty?
   A: Usually, but not always.

   unique_ptr is specified to be equal to nullptr after being moved from!

   vector has no standard-defined moved-from state like some types do
   For the move constructor, yes, the moved-from vector will always be empty because of the
   complexity requirement. For the move assignment, it depends on the allocator.
   https://stackoverflow.com/questions/17730689/is-a-moved-from-vector-always-empty.

   std::pair remains the same after being std::move.


   std::vector<int> first(20,10); // allocate 20 ints
   std::vector<int> second(std::move(first)); // leaves first in unspecified state'
   second[0] = 42; // modify second
   first = std::move(second); // moves back, leaves second in unspecified state
*/
