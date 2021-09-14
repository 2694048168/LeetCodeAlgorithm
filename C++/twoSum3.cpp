/**
 * @File    : twoSum3.cpp
 * @Brief   : 和为s的两个数字
 * @Link    : https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-14
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        //双指针
        std::vector<int> ans;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int tmp = nums[left] + nums[right];
            if (tmp == target)
            {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                break;
            }
            else if (tmp > target)
            {
                --right;
            }
            else
            {
                ++left;
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

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;

    Solution solution;
    auto two_sum_num = solution.twoSum(nums, target);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(two_sum_num);

    return 0;
}
