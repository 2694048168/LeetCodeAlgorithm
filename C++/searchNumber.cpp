/**
 * @File    : searchNumber.cpp
 * @Brief   : 在排序数组中查找数字 I 统计一个数字在排序数组中出现的次数。
 * @Link    : https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-05
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int binarySearch(std::vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    int search(std::vector<int> &nums, int target)
    {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target)
        {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 6;
    // std::vector<int> nums{5, 7, 7, 8, 8, 10};
    // int target = 8;

    Solution solution;
    auto count_target = solution.search(nums, target);
    std::cout << "The solution of this problem  is " << count_target << std::endl;

    return 0;
}
