/**
 * @File    : lengthOfLIS.cpp
 * @Brief   : 最长递增子序列 动态规划
 * @Link    : https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

/** 动态规划
 * 1.可能出现的问题：
 *    - 动态规划基础
 *    - 背包问题
 *    - 打家劫舍问题
 *    - 股票问题
 *    - 子序列问题
 * 
 * 2.重要思考点：
 *    - dp 数组的表示含义以及对应下标表示的意思
 *    - 递推公式
 *    - dp 数组的初始化值情况
 *    - 遍历的顺序 (两次循环)
 *    - 调试问题 —— 打印 dp 数组
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution2
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        int max_length = 0, n = nums.size();
        if (n <= 1)
        {
            return n;
        }

        std::vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            max_length = std::max(max_length, dp[i]);
        }
        return max_length;
    }
};

// binary search algorithm
class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }

        std::vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i)
        {
            if (dp.back() < nums[i])
            {
                dp.push_back(nums[i]);
            }
            else
            {
                auto iter = std::lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
        }
        return dp.size();
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    // std::vector<int> nums{0, 1, 0, 3, 2, 3};
    // std::vector<int> nums{7, 7, 7, 7, 7, 7, 7};

    Solution solution;
    auto max_length = solution.lengthOfLIS(nums);
    std::cout << "The solution of this problem is " << max_length << std::endl;

    return 0;
}
