/**
 * @File    : maxSlidingWindowNums.cpp
 * @Brief   : 动窗口的最大值
 * @Link    : https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-28
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        std::vector<int> maxs;
        if (nums.size() == 0)
            return maxs;
        std::vector<int> tmp;
        int max = nums[0];
        for (int i = 1; i < k; i++)
        {
            if (nums[i] > max)
                max = nums[i];
        }
        maxs.push_back(max);
        for (int i = 1; i < nums.size() - k + 1; i++)
        {
            if (nums[i - 1] == max)
            {
                max = nums[i];
                for (int j = i; j < i + k; j++)
                {
                    if (nums[j] > max)
                        max = nums[j];
                }
            }
            else if (nums[i + k - 1] > max)
                max = nums[i + k - 1];
            maxs.push_back(max);
        }
        return maxs;
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

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution solution;
    auto max_slide_win = solution.maxSlidingWindow(nums, k);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(max_slide_win);

    return 0;
}
