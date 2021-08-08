/**
 * @File    : maxArea.cpp
 * @Brief   : 盛最多水的容器    
 * @Link    : https://leetcode-cn.com/problems/container-with-most-water/
 * @Author  : Wei Li
 * @Date    : 2021-08-08
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right)
        {
            int area = std::min(height[left], height[right]) * (right - left);
            maxArea = std::max(maxArea, area);
            if (height[left] <= height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return maxArea;
    }
};

// -------------------------------
int main(int argc, char** argv)
{
    // std::vector<int> height{1, 1};
    // std::vector<int> height{1, 2, 1};
    std::vector<int> height{4, 3, 2, 1, 4};

    Solution solution;
    int max_area = solution.maxArea(height);
    std::cout << "The solution of this problem is " << max_area << std::endl;
    
    return 0;
}
