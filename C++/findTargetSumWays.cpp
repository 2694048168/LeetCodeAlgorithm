/**
 * @File    : findTargetSumWays.cpp
 * @Brief   : 目标和 动态规划
 * @Link    : https://leetcode-cn.com/problems/target-sum/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        int sum = 0;
        for (int &num : nums)
        {
            sum += num;
        }
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0)
        {
            return 0;
        }
        int neg = diff / 2;
        std::vector<int> dp(neg + 1);
        dp[0] = 1;
        for (int &num : nums)
        {
            for (int j = neg; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums { 1, 1, 1, 1, 1 };
    int target = 3;

    Solution solution;
    auto sum_ways = solution.findTargetSumWays(nums, target);
    std::cout << "The solution of this problem is " << sum_ways << std::endl;

    return 0;
}
