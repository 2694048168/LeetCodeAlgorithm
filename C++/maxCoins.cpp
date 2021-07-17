/**
 * @File    : maxCoins.cpp
 * @Brief   : 戳气球 分治算法策略 & 动态规划策略
 * @Link    : https://leetcode-cn.com/problems/burst-balloons/
 * @Author  : Wei Li
 * @Date    : 2021-07-17
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution2
{
public:
    std::vector<std::vector<int>> rec;
    std::vector<int> val;

public:
    int solve(int left, int right)
    {
        if (left >= right - 1)
        {
            return 0;
        }
        if (rec[left][right] != -1)
        {
            return rec[left][right];
        }
        for (int i = left + 1; i < right; i++)
        {
            int sum = val[left] * val[i] * val[right];
            sum += solve(left, i) + solve(i, right);
            rec[left][right] = std::max(rec[left][right], sum);
        }
        return rec[left][right];
    }

    int maxCoins(std::vector<int> &nums)
    {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 1; i <= n; i++)
        {
            val[i] = nums[i - 1];
        }
        val[0] = val[n + 1] = 1;
        rec.resize(n + 2, std::vector<int>(n + 2, -1));
        return solve(0, n + 1);
    }
};

// dp
class Solution
{
public:
    int maxCoins(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<std::vector<int>> rec(n + 2, std::vector<int>(n + 2));
        std::vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j <= n + 1; j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = std::max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{3, 1, 5, 8};
    // std::vector<int> nums{1, 5};

    Solution solution;
    auto max_coins = solution.maxCoins(nums);
    std::cout << "The solution of this problem is " << max_coins << std::endl;

    return 0;
}
