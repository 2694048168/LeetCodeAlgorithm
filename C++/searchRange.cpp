/**
 * @File    : searchRange.cpp
 * @Brief   : 在排序数组中查找元素的第一个和最后一个位置
 * @Link    : https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @Author  : Wei Li
 * @Date    : 2021-07-08
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return std::vector<int>{-1, -1};
        }
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1;
        if (lower == nums.size() || nums[lower] != target)
        {
            return std::vector<int>{-1, -1};
        }
        return std::vector<int>{lower, upper};
    }

    // 辅助函数
    int lower_bound(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    // Auxiliary function
    int upper_bound(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};


template <typename T>
void DisplayElement(const T& container)
{
    std::cout << "[";
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        std::cout << *element << ",";
    }
    std::cout << "]" << std::endl;
}


// --------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    // int target = 6;

    auto solution = Solution();
    auto index_target = solution.searchRange(nums, target);
    DisplayElement(index_target);

    return 0;
}
