/**
 * @File    : numberOfArithmeticSlices.cpp
 * @Brief   : 等差数列划分 动态规划
 * @Link    : https://leetcode-cn.com/problems/arithmetic-slices/
 * @Author  : Wei Li
 * @Date    : 2021-07-13
*/

#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:
    int numberOfArithmeticSlices(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }

        std::vector<int> dp(n, 0);
        for (int i = 2; i < n; ++i)
        {
            // 满足等差条件
            if (nums[i] - nums[ i -1] == nums[i - 1] - nums[i - 2])
            {
                // 累加
                dp[i] = dp[i - 1] + 1;
            }
        }
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};

// -----------------------------
int main(int argc, char** argv)
{
    std::vector<int> nums{1, 2, 3, 4};

    Solution solution;
    int num_arithmetic_slices = solution.numberOfArithmeticSlices(nums);
    std::cout << "The solution of this prlblem : " << num_arithmetic_slices << std::endl;
    
    return 0;
}
