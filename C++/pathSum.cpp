/**
 * @File    : pathSum.cpp
 * @Brief   : 路径总和 III
 * @Link    : https://leetcode-cn.com/problems/path-sum-iii/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
*/

#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // 主函数
    int pathSum(TreeNode *root, int sum)
    {
        return root ? pathSumStartWithRoot(root, sum) +
                          pathSum(root->left, sum) + pathSum(root->right, sum)
                    : 0;
    }
    // 辅函数
    int pathSumStartWithRoot(TreeNode *root, int sum)
    {
        if (!root)
        {
            return 0;
        }
        int count = root->val == sum ? 1 : 0;
        count += pathSumStartWithRoot(root->left, sum - root->val);
        count += pathSumStartWithRoot(root->right, sum - root->val);
        return count;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
