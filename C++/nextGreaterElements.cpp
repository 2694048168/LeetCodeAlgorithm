/**
 * @File    : nextGreaterElements.cpp
 * @Brief   : 下一个更大元素 II
 * @Link    : https://leetcode-cn.com/problems/next-greater-element-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
    std::vector<int> nextGreaterElements(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> ret(n, -1);
        std::stack<int> stk;
        for (int i = 0; i < n * 2 - 1; i++)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i % n])
            {
                ret[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ret;
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
    std::vector<int> nums{1, 2, 1};

    Solution solution;
    auto next_greater_element = solution.nextGreaterElements(nums);
    DisplayElement(next_greater_element);

    return 0;
}
