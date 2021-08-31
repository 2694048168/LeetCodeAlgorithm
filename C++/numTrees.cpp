/**
 * @File    : numTrees.cpp
 * @Brief   : 不同的二叉搜索树
 * @Link    : https://leetcode-cn.com/problems/unique-binary-search-trees/
 * @Author  : Wei Li
 * @Date    : 2021-08-31
*/

#include <iostream>
#include <vector>

// 动态规划
class Solution2
{
public:
    int numTrees(int n)
    {
        std::vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

// 数学方法
class Solution
{
public:
    int numTrees(int n)
    {
        long long C = 1;
        for (int i = 0; i < n; ++i)
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    int num = 3;

    Solution solution;
    auto num_trees = solution.numTrees(num);
    std::cout << "The solution of this problem is " << num_trees << std::endl;

    return 0;
}
