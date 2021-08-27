/**
 * @File    : trapMIN.cpp
 * @Brief   : 直方图的水量
 * @Link    : https://leetcode-cn.com/problems/volume-of-histogram-lcci/
 * @Author  : Wei Li
 * @Date    : 2021-08-27
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

int main(int argc, char **argv)
{
    std::vector<int> nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution solution;
    int trap_num = solution.trap(nums);
    std::cout << "The solution of this problem is " << trap_num << std::endl;

    return 0;
}
