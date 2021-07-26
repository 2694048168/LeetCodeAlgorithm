/**
 * @File    : maxSlidingWindow.cpp
 * @Brief   : 滑动窗口最大值
 * @Link    : https://leetcode-cn.com/problems/sliding-window-maximum/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>
#include <deque>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        std::deque<int> dq;
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, -1};
    int k = 1;

    Solution solution;
    auto max_slide_window = solution.maxSlidingWindow(nums, k);
    DisplayElement(max_slide_window);

    return 0;
}
