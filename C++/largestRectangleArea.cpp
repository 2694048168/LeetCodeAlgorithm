/**
 * @File    : largestRectangleArea.cpp
 * @Brief   : 柱状图中最大的矩形
 * @Link    : https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 * @Author  : Wei Li
 * @Date    : 2021-08-13
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    int largestRectangleArea(std::vector<int> &heights)
    {
        int n = heights.size();
        std::vector<int> left(n), right(n, n);

        std::stack<int> mono_stack;
        for (int i = 0; i < n; ++i)
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
            {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> height{2, 1, 5, 6, 2, 3};

    Solution solution;
    auto max_area = solution.largestRectangleArea(height);
    std::cout << "The soluton of this problem is " << max_area << std::endl;

    return 0;
}
