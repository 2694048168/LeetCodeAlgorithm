/**
 * @File    : longestConsecutive.cpp
 * @Brief   : 最长连续序列
 * @Link    : https://leetcode-cn.com/problems/longest-consecutive-sequence/
 * @Author  : Wei Li
 * @Date    : 2021-07-26
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_set<int> hash;
        for (const int &num : nums)
        {
            hash.insert(num);
        }
        int ans = 0;
        while (!hash.empty())
        {
            int cur = *(hash.begin());
            hash.erase(cur);
            int next = cur + 1, prev = cur - 1;
            while (hash.count(next))
            {
                hash.erase(next++);
            }
            while (hash.count(prev))
            {
                hash.erase(prev--);
            }
            ans = std::max(ans, next - prev - 1);
        }
        return ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{100, 4, 200, 1, 3, 2};
    std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    Solution solution;
    auto longest_consecutive = solution.longestConsecutive(nums);
    std::cout << "The solution of this problem is " << longest_consecutive << std::endl;

    return 0;
}
