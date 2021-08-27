/**
 * @File    : maxSum.cpp
 * @Brief   : 最大得分
 * @Link    : https://leetcode-cn.com/problems/get-the-maximum-score/
 * @Author  : Wei Li
 * @Date    : 2021-08-27
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    static constexpr int mod = 1000000007;

public:
    int maxSum(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        long long best1 = 0, best2 = 0;
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            if (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    best1 += nums1[i];
                    ++i;
                }
                else if (nums1[i] > nums2[j])
                {
                    best2 += nums2[j];
                    ++j;
                }
                else
                {
                    long long best = std::max(best1, best2) + nums1[i];
                    best1 = best2 = best;
                    ++i;
                    ++j;
                }
            }
            else if (i < m)
            {
                best1 += nums1[i];
                ++i;
            }
            else if (j < n)
            {
                best2 += nums2[j];
                ++j;
            }
        }
        return std::max(best1, best2) % mod;
    }
};

class Solution
{
public:
    int maxSum(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        //找到 nums1 nums2 相等元素之间值最大的路径
        int i = 0;
        int mod = 1e9 + 7;
        int j = 0;
        long res = 0;
        long sum1 = 0;
        long sum2 = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                sum1 += nums1[i++];
            }
            else if (nums1[i] > nums2[j])
            {
                sum2 += nums2[j++];
            }
            else
            {
                res += (std::max(sum1, sum2) + nums1[i]);
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        while (i < nums1.size())
        {
            sum1 += nums1[i++];
        }
        while (j < nums2.size())
        {
            sum2 += nums2[j++];
        }
        res += std::max(sum1, sum2);
        res = res % mod;
        return res;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums1{1, 4, 5, 8, 9, 11, 19};
    std::vector<int> nums2{2, 3, 4, 11, 12};
    // std::vector<int> nums1{2, 4, 5, 8, 10};
    // std::vector<int> nums2{4, 6, 8, 9};

    Solution solution;
    auto max_sum = solution.maxSum(nums1, nums2);
    std::cout << "The solution of this problem is " << max_sum << std::endl;

    return 0;
}
