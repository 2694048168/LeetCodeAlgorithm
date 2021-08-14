/**
 * @File    : trap.cpp
 * @Brief   : 接雨水
 * @Link    : https://leetcode-cn.com/problems/trapping-rain-water/
 * @Author  : Wei Li
 * @Date    : 2021-08-14
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 双指针策略
class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right)
        {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);
            if (height[left] < height[right])
            {
                ans += leftMax - height[left];
                ++left;
            }
            else
            {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> height{4, 2, 0, 3, 2, 5};

    Solution solution;
    auto max_trap = solution.trap(height);
    std::cout << "The solution of this proble is " << max_trap << std::endl;

    return 0;
}
