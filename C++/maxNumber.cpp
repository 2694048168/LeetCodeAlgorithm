/**
 * @File    : maxNumber.cpp
 * @Brief   : 拼接最大数
 * @Link    : https://leetcode-cn.com/problems/create-maximum-number/
 * @Author  : Wei Li
 * @Date    : 2021-08-25
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
public:
    std::vector<int> maxNumber(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        std::vector<int> maxSubsequence(k, 0);
        int start = std::max(0, k - n), end = std::min(k, m);
        for (int i = start; i <= end; i++)
        {
            std::vector<int> subsequence1(MaxSubsequence(nums1, i));
            std::vector<int> subsequence2(MaxSubsequence(nums2, k - i));
            std::vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0)
            {
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;
    }

    std::vector<int> MaxSubsequence(std::vector<int> &nums, int k)
    {
        int length = nums.size();
        std::vector<int> stack(k, 0);
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++)
        {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0)
            {
                top--;
                remain--;
            }
            if (top < k - 1)
            {
                stack[++top] = num;
            }
            else
            {
                remain--;
            }
        }
        return stack;
    }

    std::vector<int> merge(std::vector<int> &subsequence1, std::vector<int> &subsequence2)
    {
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0)
        {
            return subsequence2;
        }
        if (y == 0)
        {
            return subsequence1;
        }
        int mergeLength = x + y;
        std::vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++)
        {
            if (compare(subsequence1, index1, subsequence2, index2) > 0)
            {
                merged[i] = subsequence1[index1++];
            }
            else
            {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    int compare(std::vector<int> &subsequence1, int index1, std::vector<int> &subsequence2, int index2)
    {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y)
        {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0)
            {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
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
    std::vector<int> nums1{3, 9};
    std::vector<int> nums2{8, 9};
    int k = 3;
    // std::vector<int> nums1{3, 4, 6, 5};
    // std::vector<int> nums2{9, 1, 2, 5, 8, 3};
    // int k = 5;

    Solution solution;
    auto max_number_order = solution.maxNumber(nums1, nums2, k);
    DisplayElement(max_number_order);

    return 0;
}
