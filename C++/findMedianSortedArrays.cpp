/**
 * @File    : findMedianSortedArrays.cpp
 * @Brief   : 寻找两个正序数组的中位数
 * @Link    : https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * @Author  : Wei Li
 * @Date    : 2021-07-04
*/

#include <iostream>
#include <vector>
#include <memory>

// ---------------------------------------
class Solution
{
public:
    int getKthElement(const std::vector<int>& nums1, const std::vector<int>& nums2, size_t k)
    {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除, 即直接舍弃小数点后的数值，取计算结果的整数部分
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于"删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        auto m = nums1.size();
        auto n = nums2.size();
        size_t index1 = 0, index2 = 0;

        while (true)
        {
            // 边界情况
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            if (k == 1)
            {
                return std::min(nums1[index1], nums2[index2]);
            }

            // binary search algorithm
            auto newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
            auto newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
            auto pivot1 = nums1[newIndex1];
            auto pivot2 = nums2[newIndex2];

            if (pivot1 <= pivot2)
            {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        // size_t totalLength = nums1.size() + nums2.size();
        auto totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1)
        {
            // value of totalLength is enev
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }
        else
        {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};


class Solution2 
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) 
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        auto m = nums1.size();
        auto n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right) 
        {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            auto i = (left + right) / 2;
            auto j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            auto nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            auto nums_i = (i == m ? INT_MAX : nums1[i]);
            auto nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            auto nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j) 
            {
                median1 = std::max(nums_im1, nums_jm1);
                median2 = std::min(nums_i, nums_j);
                left = i + 1;
            } 
            else 
            {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};


// ---------------------------------------
int main(int argc, char** argv)
{
    // std::vector<int> nums1 = {1, 2, 3, 4};
    // std::vector<int> nums2 = {3, 4, 5, 6, 7};
    // std::vector<int> nums2 = {3, 4, 5, 6};
    // std::vector<int> nums2 = {3, 4, 5};

    std::vector<int> nums2 = {-2, -1};
    std::vector<int> nums1 = {3};

    // auto solution = Solution();
    // auto solution = Solution2();
    // Solution solution;
    auto solution = std::make_unique<Solution2>();
    // auto medianValue = solution.findMedianSortedArrays(nums1, nums2);
    auto medianValue = solution->findMedianSortedArrays(nums1, nums2);
    std::cout << "The median value of sorted nums1 and nums2 is : " << medianValue << std::endl;

    return 0;
}