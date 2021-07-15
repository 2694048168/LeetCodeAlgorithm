/**
 * @File    : canPartition.cpp
 * @Brief   : 分割等和子集 背包问题 —— 动态规划
 * @Link    : https://leetcode-cn.com/problems/partition-equal-subset-sum/
 * @Author  : Wei Li
 * @Date    : 2021-07-15
*/

// Reference <<LeetCode 101: A LeetCode Grinding Guide (C++ Version)>>
// 7.6 背包问题

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution2
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *std::max_element(nums.begin(), nums.end());
        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)
        {
            return false;
        }
        std::vector<std::vector<int>> dp(n, std::vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

// 进行空间压缩  注意对数字和的遍历需要逆向
class Solution
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
        {
            return false;
        }
            
        int target = sum / 2, n = nums.size();
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = target; j >= nums[i - 1]; --j)
            {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[target];
    }
};

// ----------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1, 5, 11, 5};
    // std::vector<int> nums{1, 2, 3, 5};
    std::vector<int> nums{1, 5, 10, 6};

    Solution solution;
    bool check_partition = solution.canPartition(nums);
    std::cout << "The solution of this problem is " << std::boolalpha << check_partition << std::endl;

    return 0;
}
