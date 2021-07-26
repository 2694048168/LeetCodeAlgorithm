/**
 * @File    : subarraySum.cpp
 * @Brief   : 和为K的子数组
 * @Link    : https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        int count = 0, psum = 0;
        std::unordered_map<int, int> hashmap;
        hashmap[0] = 1; // 初始化很重要
        for (int i : nums)
        {
            psum += i;
            count += hashmap[psum - k];
            ++hashmap[psum];
        }
        return count;
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 1, 1};
    int k = 2;

    Solution solution;
    auto num_subarray = solution.subarraySum(nums, k);
    std::cout << "The solution of this problem is " << num_subarray << std::endl;

    return 0;
}
