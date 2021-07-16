/**
 * @File    : maxSubArray.cpp
 * @Brief   :  最大子序和 动态规划
 * @Link    : https://leetcode-cn.com/problems/maximum-subarray/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums)
        {
            pre = std::max(pre + x, x);
            maxAns = std::max(maxAns, pre);
        }
        return maxAns;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solution;
    auto max_sum = solution.maxSubArray(nums);
    std::cout << "The solution of this problem is " << max_sum << std::endl;

    return 0;
}
