/**
 * @File    : permute.cpp
 * @Brief   : 全排列 回溯算法
 * @Link    : https://leetcode-cn.com/problems/permutations/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

/**
 * 回溯法（backtracking）是优先搜索的一种特殊情况，又称为试探法，常用于需要记录节点状态的深度优先搜索。
 * 通常来说，排列、组合、选择类问题使用回溯法比较方便。
 * 顾名思义，回溯法的核心是回溯。在搜索到某一节点的时候，如果发现目前的节点（及其子节点）并不是需求目标时，
 * 回退到原来的节点继续搜索，并且把在目前节点修改的状态还原。
 * 这样的好处是我们可以始终只对图的总状态进行修改，而非每次遍历时新建一个图来储存状态。
 * 
 * 在具体的写法上，它与普通的深度优先搜索一样，都有 [修改当前节点状态]![递归子节点] 的步骤，
 * 只是多了回溯的步骤，变成了 [修改当前节点状态]![递归子节点]![回改当前节点状态]。
 * 
 * 可以记住两个小诀窍， 一是按引用传状态， 二是所有的状态修改在递归完成后回改。
 * 回溯法修改一般有两种情况，一种是修改最后一位输出，比如排列组合；一种是修改访问标记，比如矩阵里搜字符串
 */
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // 主函数
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
    // 辅函数
    void backtracking(std::vector<int> &nums, int level, std::vector<std::vector<int>> &ans)
    {
        if (level == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++)
        {
            std::swap(nums[i], nums[level]);    // 修改当前节点状态
            backtracking(nums, level + 1, ans); // 递归子节点
            std::swap(nums[i], nums[level]);    // 回改当前节点状态
        }
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
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<int> nums{1, 2, 3};

    Solution solution;
    auto permute_vec = solution.permute(nums);
    DisplayElement(permute_vec);

    return 0;
}
