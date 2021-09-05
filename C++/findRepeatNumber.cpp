/**
 * @File    : findRepeatNumber.cpp
 * @Brief   : 数组中重复的数字
 * @Link    : https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-05
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findRepeatNumber(std::vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == i)
            {
                ++i;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            std::swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{2, 3, 1, 0, 2, 5, 3};

    Solution solution;
    auto repeat_number = solution.findRepeatNumber(nums);
    std::cout << "The solution of this problem is " << repeat_number << std::endl;

    return 0;
}
