/**
 * @File    : buildTree2.cpp
 * @Brief   : 从中序与后序遍历序列构造二叉树
 * @Link    : https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * @Author  : Wei Li
 * @Date    : 2021-08-02
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
    int post_idx;
    std::unordered_map<int, int> idx_map;

public:
    TreeNode *helper(int in_left, int in_right, std::vector<int> &inorder, std::vector<int> &postorder)
    {
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right)
        {
            return nullptr;
        }

        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode *root = new TreeNode(root_val);

        // 根据 root 所在位置分成左右两棵子树
        int index = idx_map[root_val];

        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
    {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立（元素，下标）键值对的哈希表
        int idx = 0;
        for (auto &val : inorder)
        {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
