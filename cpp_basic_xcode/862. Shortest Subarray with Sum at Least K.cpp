//
//  862. Shortest Subarray with Sum at Least K.cpp
//  cpp_basic_xcode
//
//  Created by Harvey MAO on 2021/10/29.
//

#include <iostream>
#include <deque>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long int> cum_sum;
        cum_sum.emplace_back(0);
        
        // cum_sum[i] = sum fo nums[0,...,i-1]
        for (auto iter(nums.begin()); iter != nums.end(); iter++) {
            cum_sum.emplace_back(cum_sum.back() + *iter);
        }
        
        // maintain a deque of indices for which the cum_sums
        // are in ascending order
        deque<int> deq;
        deq.emplace_back(0);
        
        int max_int = std::numeric_limits<int>::max();
        int min_len = max_int;
        
        // try all subarrays ending with ith number in nums, namely nums[i-1]
        for (int i(1); i < cum_sum.size(); i++) {
           // pop out the left cum_sums which make range sum >= k
            while (!deq.empty() and cum_sum[i] - cum_sum[deq.front()] >= k) {
                min_len = min(min_len, i - deq.front());
                deq.pop_front();
            }
            
            // remove all elements in the deque which are >= cum_sum[i]
            // to preserve the ascending order
            while (!deq.empty() and cum_sum[deq.back()] >= cum_sum[i]) {
                deq.pop_back();
            }
                
            // add i into the deq
            deq.emplace_back(i);
        }
        
        
        return  min_len < max_int ? min_len : -1;
    }
};

