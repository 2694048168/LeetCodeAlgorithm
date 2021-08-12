/**
 * @File    : firstMissingPositive.cpp
 * @Brief   : 缺失的第一个正数
 * @Link    : https://leetcode-cn.com/problems/first-missing-positive/
 * @Author  : Wei Li
 * @Date    : 2021-08-12
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 方法一：哈希表
class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int n = nums.size();
        for (int &num : nums)
        {
            if (num <= 0)
            {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int num = abs(nums[i]);
            if (num <= n)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// 方法二：置换
class Solution2
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                std::swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 0};
    // std::vector<int> nums{3, 4, -1, 1};
    // std::vector<int> nums{7, 8, 9, 11, 12};

    Solution solution;
    auto first_missing_positive = solution.firstMissingPositive(nums);
    std::cout << "The solution of this problem is " << first_missing_positive << std::endl;

    return 0;
}
