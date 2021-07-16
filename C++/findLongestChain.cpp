/**
 * @File    : findLongestChain.cpp
 * @Brief   : 最长数对链 动态规划
 * @Link    : https://leetcode-cn.com/problems/maximum-length-of-pair-chain/
 * @Author  : Wei Li
 * @Date    : 2021-07-16
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // 动态规划 + 二分法，时间复杂度 big-O(nlogn)，空间复杂度 O(n)
    int findLongestChain_2(std::vector<std::vector<int>> &pairs)
    {
        if (pairs.empty())
            return 0;
        std::sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
                  { return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]); });
        std::vector<std::vector<int>> dp;
        for (auto &p : pairs)
        {
            //二分法寻找大于等于p[0]的最小值dp[i][1]
            int left = 0, right = dp.size();
            while (left < right)
            { //进入while循环区间内至少有2个元素，退出循环的极值只有0或size
                int mid = left + ((right - left) >> 1);
                if (dp[mid][1] >= p[0])
                    right = mid;
                else
                    left = mid + 1;
            }
            //dp[size-1][1]<p[0]，则更新最长数对链的长度
            if (left >= dp.size())
                dp.emplace_back(p);
            //dp[left][1]大于（等于）p[0]同时也大于p[1]，那么我们更新dp[left]为p，这样可以将left变小，以便形成最长的数对链
            else if (dp[left][1] > p[1])
                dp[left] = p;
        }
        return dp.size();
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<std::vector<int>> pairs = {{1, 2},
                                           {2, 3},
                                           {3, 4}};

    Solution solution;
    auto max_chain = solution.findLongestChain_2(pairs);
    std::cout << "The solution of this problem is " << max_chain << std::endl;

    return 0;
}
