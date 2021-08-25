/**
 * @File    : minPatches.cpp
 * @Brief   : 按要求补齐数组
 * @Link    : https://leetcode-cn.com/problems/patching-array/
 * @Author  : Wei Li
 * @Date    : 2021-08-25
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int minPatches(std::vector<int> &nums, int n)
    {
        int patches = 0;
        long long x = 1;
        int length = nums.size(), index = 0;
        while (x <= n)
        {
            if (index < length && nums[index] <= x)
            {
                x += nums[index];
                index++;
            }
            else
            {
                x <<= 1;
                patches++;
            }
        }
        return patches;
    }
};

// ---------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 2};
    int n = 5;
    // std::vector<int> nums{1, 5, 10};
    // int n = 20;

    Solution solution;
    auto min_patches = solution.minPatches(nums, n);
    std::cout << "The solution of this problem is " << min_patches << std::endl;

    return 0;
}
