/**
 * @File    : findMin.cpp
 * @Brief   : 寻找旋转排序数组中的最小值 II
 * @Link    : https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-09
*/

#include <iostream>
#include <vector>

// 二分查找算法适合排序好的数组进行检索或查找
class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high])
            {
                high = pivot;
            }
            else if (nums[pivot] > nums[high])
            {
                low = pivot + 1;
            }
            else
            {
                high -= 1;
            }
        }
        return nums[low];
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums = {1, 3, 5};
    std::vector<int> nums = {2, 2, 2, 0, 1};

    auto solution = Solution();
    int value_min = solution.findMin(nums);
    std::cout << "The solution of this problem is : " << value_min << std::endl;

    return 0;
}