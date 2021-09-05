/**
 * @File    : missingNumberOnly.cpp
 * @Brief   : 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
 *           在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
 * @Link    : https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-05
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] != mid)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[r] == r)
            ++r; //特殊情况
        return r;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 9};

    Solution solution;
    auto missing_number = solution.missingNumber(nums);
    std::cout << "The solution of this problem is " << missing_number << std::endl;

    return 0;
}
