/**
 * @File    : combine.cpp
 * @Brief   :  组合 回溯算法
 * @Link    : https://leetcode-cn.com/problems/combinations/
 * @Author  : Wei Li
 * @Date    : 2021-07-11
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    // 主函数
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> ans;
        std::vector<int> comb(k, 0);
        int count = 0;
        backtracking(ans, comb, count, 1, n, k);
        return ans;
    }
    // 辅函数
    void backtracking(std::vector<std::vector<int>> &ans, std::vector<int> &comb, int &count, int pos, int n, int k)
    {
        if (count == k)
        {
            ans.push_back(comb);
            return;
        }
        for (int i = pos; i <= n; ++i)
        {
            comb[count++] = i;                           // 修改当前节点状态
            backtracking(ans, comb, count, i + 1, n, k); // 递归子节点
            --count;                                     // 回改当前节点状态
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


// ---------------------------------
int main(int argc, char **argv)
{
    int n = 4, k = 2;

    Solution solution;
    auto combine_vec = solution.combine(n, k);
    std::cout << "The solution of this problem: " << std::endl;
    DisplayElement(combine_vec);

    return 0;
}
