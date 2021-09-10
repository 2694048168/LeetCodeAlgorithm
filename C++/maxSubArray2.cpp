/**
 * @File    : maxSubArray2.cpp
 * @Brief   : 连续子数组的最大和
 * @Link    : https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-10
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
    auto max_subarray_sum = solution.maxSubArray(nums);
    std::cout << "The solution of this problem is " << max_subarray_sum << std::endl;

    return 0;
}
