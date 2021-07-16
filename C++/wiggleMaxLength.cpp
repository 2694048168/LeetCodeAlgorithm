/**
 * @File    : wiggleMaxLength.cpp
 * @Brief   : 摆动序列 动态规划
 * @Link    : https://leetcode-cn.com/problems/wiggle-subsequence/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int wiggleMaxLength(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return n;
        }
        std::vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                up[i] = std::max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if (nums[i] < nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = std::max(up[i - 1] + 1, down[i - 1]);
            }
            else
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return std::max(up[n - 1], down[n - 1]);
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};

    Solution solution;
    auto max_length = solution.wiggleMaxLength(nums);
    std::cout << "The solution of this problem is " << max_length << std::endl;

    return 0;
}
