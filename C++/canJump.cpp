/**
 * @File    : canJump.cpp
 * @Brief   : 跳跃游戏
 * @Link    : https://leetcode-cn.com/problems/jump-game/
 * @Author  : Wei Li
 * @Date    : 2021-08-24
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = std::max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{3, 2, 1, 0, 4};
    std::vector<int> nums{2, 3, 1, 1, 4};

    Solution solution;
    bool check_jump = solution.canJump(nums);
    std::cout << "The solution of this problem is " << std::boolalpha << check_jump << std::endl;

    return 0;
}
