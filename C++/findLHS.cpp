/**
 * @File    : findLHS.cpp
 * @Brief   : 最长和谐子序列
 * @Link    : https://leetcode-cn.com/problems/longest-harmonious-subsequence/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int findLHS(std::vector<int> &nums)
    {
        std::unordered_map<int, int> num2cnt;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            ++num2cnt[nums[i]];
        }

        // 记录最大和的结果
        int res = 0;
        for (auto iter = num2cnt.begin(); iter != num2cnt.end(); ++iter)
        {
            int curr = iter->first;
            if (num2cnt.find(curr + 1) != num2cnt.end())
            {
                res = std::max(res, iter->second + num2cnt[curr + 1]);
            }
        }
        return res;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};

    Solution solution;
    auto find_lhs = solution.findLHS(nums);
    std::cout << "The solution of this problem is " << find_lhs <<std::endl;

    return 0;
}
