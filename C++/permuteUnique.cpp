/**
 * @File    : permuteUnique.cpp
 * @Brief   : 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * @Link    : https://leetcode-cn.com/problems/permutations-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-12
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 方法一：搜索回溯
class Solution
{
    std::vector<int> vis;

public:
    void backtrack(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int idx, std::vector<int> &perm)
    {
        if (idx == nums.size())
        {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
            {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element = container.begin(); element != container.end(); ++element)
    {
        for (auto value = element->begin(); value != element->end(); ++value)
        {
            std::cout << *value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// ------------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1, 1, 2};
    std::vector<int> nums{1, 2, 3};

    Solution solution;
    auto permute_unique_vec = solution.permuteUnique(nums);
    std::cout << "The solutio of this problem is : " << std::endl;
    DisplayElement(permute_unique_vec);

    return 0;
}
