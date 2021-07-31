/**
 * @File    : delNodes.cpp
 * @Brief   : 删点成林
 * @Link    : https://leetcode-cn.com/problems/delete-nodes-and-return-forest/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
*/

#include <iostream>
#include <vector>
#include <unordered_set>

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
    std::vector<TreeNode *> delNodes(TreeNode *root, std::vector<int> &to_delete)
    {
        std::vector<TreeNode *> forest;
        std::unordered_set<int> dict(to_delete.begin(), to_delete.end());
        root = helper(root, dict, forest);
        if (root)
        {
            forest.push_back(root);
        }
        return forest;
    }
    // 辅函数
    TreeNode *helper(TreeNode *root, std::unordered_set<int> &dict, std::vector<TreeNode *> &forest)
    {
        if (!root)
        {
            return root;
        }
        root->left = helper(root->left, dict, forest);
        root->right = helper(root->right, dict, forest);
        if (dict.count(root->val))
        {
            if (root->left)
            {
                forest.push_back(root->left);
            }
            if (root->right)
            {
                forest.push_back(root->right);
            }
            root = NULL;
        }
        return root;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
