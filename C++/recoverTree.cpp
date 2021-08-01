/**
 * @File    : recoverTree.cpp
 * @Brief   : 恢复二叉搜索树
 * @Link    : https://leetcode-cn.com/problems/recover-binary-search-tree/
 * @Author  : Wei Li
 * @Date    : 2021-08-01
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
    void recoverTree(TreeNode *root)
    {
        TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;
        inorder(root, mistake1, mistake2, prev);
        if (mistake1 && mistake2)
        {
            int temp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = temp;
        }
    }
    // 辅函数
    void inorder(TreeNode *root, TreeNode *&mistake1, TreeNode *&mistake2, TreeNode *&prev)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            inorder(root->left, mistake1, mistake2, prev);
        }
        if (prev && root->val < prev->val)
        {
            if (!mistake1)
            {
                mistake1 = prev;
                mistake2 = root;
            }
            else
            {
                mistake2 = root;
            }
            std::cout << mistake1->val;
            std::cout << mistake2->val;
        }
        prev = root;
        if (root->right)
        {
            inorder(root->right, mistake1, mistake2, prev);
        }
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
