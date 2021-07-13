/**
 * @File    : rob.cpp
 * @Brief   : 打家劫舍 动态规划
 * @Link    : https://leetcode-cn.com/problems/house-robber/
 * @Author  : Wei Li
 * @Date    : 2021-07-13
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution2
{
public:
    int rob(std::vector<int> &nums)
    {
        // 边界条件
        if (nums.empty())
        {
            return 0;
        }

        int n = nums.size();
        std::vector<int> dp(n + 1, 0);
        // 边界条件
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i)
        {
            // 状态转移方程
            dp[i] = std::max(dp[i - 1], nums[i - 1] + dp[i - 2]);
        }

        return dp[n];
    }
};

// 压缩动态规划的空间
class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        // 边界条件
        if (nums.empty())
        {
            return 0;
        }

        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        // std::vector<int> dp(n + 1, 0);
        int pre2 = 0, pre1 = 0, current;
        for (int i = 0; i < n; ++i)
        {
            // 状态转移方程
            // dp[i] = std::max(dp[i - 1], nums[i - 1] + dp[i - 2]);
            current = std::max(pre2 + nums[i], pre1);
            pre2 = pre1;
            pre1 = current;
        }

        return current;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{2, 7, 9, 3, 1};
    // std::vector<int> nums{1, 2, 3, 1};

    Solution solution;
    int num_crash = solution.rob(nums);
    std::cout << "The solution of this problem is : " << num_crash << std::endl;

    return 0;
}
