/**
 * @File    : advantageCount.cpp
 * @Brief   : 优势洗牌
 * @Link    : https://leetcode-cn.com/problems/advantage-shuffle/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
 * @Date    : 2022-10-08
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

/**
 * @brief 给定两个'大小相等'的数组 nums1 和 nums2，nums1 相对于 nums 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。
 * 返回 nums1 的任意排列，使其相对于 nums2 的优势最大化。
 *
 * Solution:
 * 1. 对 num1 进行升序排列(从小到大)
 * 2. 利用贪心思想，从 num1 逐步进行对比 num2 中的元素
 * 3. 满足条件 num1[idx] 进入结果数组中，并同时从 num1 中剔除
 * 4. 循环重复执行至 num1 数组为空
 *
 */
class Solution
{
public:
    std::vector<int> advantageCount(std::vector<int> &num1, std::vector<int> &num2)
    {
        // special case
        if (num1.empty() || (num1.size() != num2.size()))
        {
            return std::vector<int>();
        }

        std::vector<int> result_vec(num1.size(), 0);
        /* num1 升序排列，便于贪心算法 */
        std::sort(num1.begin(), num1.end()); /* non-descending order */

        std::vector<std::pair<int, int>> num2_pair;
        for (size_t i = 0; i < num2.size(); ++i)
        {
            num2_pair.push_back({num2[i], i}); /* num2 中可能存在相同的数字，通过将索引和值进行对应 */
        }
        std::sort(num2_pair.begin(), num2_pair.end());

        int left_ptr = 0, right_ptr = num1.size() - 1;
        for (int i = num2_pair.size() - 1; i >= 0; --i)
        {
            if (num1[right_ptr] > num2_pair[i].first)
            {
                result_vec[num2_pair[i].second] = num1[right_ptr];
                --right_ptr;
            }
            else{
                result_vec[num2_pair[i].second] = num1[left_ptr];
                ++left_ptr;
            }
        }
        return result_vec;
    }
};

class Solution2
{
public:
    std::vector<int> advantageCount(std::vector<int> &A, std::vector<int> &B)
    {
        int size = A.size();
        if (size == 0 || size != B.size())
        {
            return std::vector<int>();
        }
        std::vector<std::pair<int, int>> bIndex(size);
        std::vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            bIndex[i] = {B[i], i};
        }
        std::sort(A.begin(), A.end());
        std::sort(bIndex.begin(), bIndex.end());
        auto it = bIndex.begin();
        auto rIt = bIndex.rbegin();
        for (int i = 0; i < size; i++)
        {
            if (A[i] > it->first)
            {
                result[it->second] = A[i];
                it++;
            }
            else
            {
                result[rIt->second] = A[i];
                rIt++;
            }
        }
        return result;
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

// --------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums1{12, 24, 8, 32}, nums2{1, 10, 4, 11};
    std::vector<int> nums1{2, 7, 11, 15}, nums2{1, 10, 4, 11};
    // std::vector<int> nums1{12, 24, 8, 32}, nums2{13, 25, 32};
    // std::vector<int> nums1{12, 24, 8, 32}, nums2{13, 25, 32, 11};

    Solution solution;
    auto advantage_count = solution.advantageCount(nums1, nums2);
    DisplayElement(advantage_count);

    return 0;
}
