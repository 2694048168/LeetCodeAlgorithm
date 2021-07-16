/**
 * @File    : rob2.cpp
 * @Brief   : 打家劫舍 II 动态规划
 * @Link    : https://leetcode-cn.com/problems/house-robber-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int robRange(std::vector<int> &nums, int start, int end)
    {
        int first = nums[start], second = std::max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(std::vector<int> &nums)
    {
        int length = nums.size();
        if (length == 1)
        {
            return nums[0];
        }
        else if (length == 2)
        {
            return std::max(nums[0], nums[1]);
        }
        return std::max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{2, 3, 2};
    std::vector<int> nums{1, 2, 3, 1};

    Solution solution;
    auto max_cash = solution.rob(nums);
    std::cout << "The solution of this problem is " << max_cash << std::endl;

    return 0;
}
