/**
 * @File    : buildTree.cpp
 * @Brief   : 从前序与中序遍历序列构造二叉树
 * @Link    : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * @Author  : Wei Li
 * @Date    : 2021-07-31
*/

#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }
        std::unordered_map<int, int> hash;
        for (int i = 0; i < preorder.size(); ++i)
        {
            hash[inorder[i]] = i;
        }
        return buildTreeHelper(hash, preorder, 0, preorder.size() - 1, 0);
    }
    // 辅函数
    TreeNode *buildTreeHelper(std::unordered_map<int, int> &hash, std::vector<int> &preorder, int s0, int e0, int s1)
    {
        if (s0 > e0)
        {
            return nullptr;
        }
        int mid = preorder[s1], index = hash[mid], leftLen = index - s0 - 1;
        TreeNode *node = new TreeNode(mid);
        node->left = buildTreeHelper(hash, preorder, s0, index - 1, s1 + 1);
        node->right = buildTreeHelper(hash, preorder, index + 1, e0, s1 + 2 + leftLen);
        return node;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
