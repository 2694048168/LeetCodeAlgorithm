/**
 * @file min_swap.cpp
 * @author Wei Li (weili_yzzcq@163.com)
 * @brief 使序列严格递增的最小交换次数
 * @cite https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/
 * @version 0.1
 * @date 2022-10-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>

/**
 * @brief 使序列递增的最小交换次数: 有两个长度相等且不为空的整型数组 nums1 和 nums2;
 * 在一次操作中，可以交换 nums1[i] 和 nums2[i]的元素.
 *
 * 例如，如果 nums1 = [1,2,3,8], nums2 =[5,6,7,4];
 * 可以交换 i = 3 处的元素, 得到 nums1 =[1,2,3,4] 和 nums2 =[5,6,7,8],
 * 返回使 nums1 和 nums2 严格递增 所需操作的最小次数.
 * 数组 arr 严格递增 且  arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1]
 *
 */
class Solution
{
public:
    int minSwap(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // special case
        if (nums1.empty() || (nums1.size() != nums2.size()))
        {
            return -1; /* why not to be zero '0' */
        }

        int nums_size = nums1.size();
        int a = 0, b = 1;
        for (int i = 1; i < nums_size; i++)
        {
            int at = a, bt = b;
            a = b = nums_size;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
            {
                a = std::min(a, at);
                b = std::min(b, bt + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
            {
                a = std::min(a, bt);
                b = std::min(b, at + 1);
            }
        }
        return std::min(a, b);
    }
};

// -------------------------------------
int main(int argc, char const *argv[])
{
    // std::vector<int> nums1{1, 3, 5, 4};
    // std::vector<int> nums2{1, 2, 3, 7};

    // std::vector<int> nums1{0, 3, 5, 8, 9};
    // std::vector<int> nums2{2, 1, 4, 6, 9};

    std::vector<int> nums1{9, 8, 7, 3, 2, 0, 1};
    std::vector<int> nums2{12, 6, 4, 5, 11, 10, 13};

    Solution solution;
    int min_num_swap = solution.minSwap(nums1, nums2);
    std::cout << "the minimize number of swap operators: " << min_num_swap << std::endl;

    return 0;
}
