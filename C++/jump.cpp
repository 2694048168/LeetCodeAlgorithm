/**
 * @File    : jump.cpp
 * @Brief   : 跳跃游戏 II
 * @Link    : https://leetcode-cn.com/problems/jump-game-ii/
 * @Author  : Wei Li
 * @Date    : 2021-08-19
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = std::max(maxPos, i + nums[i]);
                if (i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{2, 3, 1, 1, 4};
    std::vector<int> nums{2, 3, 0, 1, 4};

    Solution solution;
    auto num_jump = solution.jump(nums);
    std::cout << "The solution of this problem is " << num_jump << std::endl;

    return 0;
}
