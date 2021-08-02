/**
 * @File    : postorderTraversal.cpp
 * @Brief   : 二叉树的后序遍历
 * @Link    : https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * @Author  : Wei Li
 * @Date    : 2021-08-02
*/

#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        std::stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty())
        {
            while (root != nullptr)
            {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev)
            {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }
            else
            {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
