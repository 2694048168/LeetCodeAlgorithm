/**
 * @File    : increasingBST.cpp
 * @Brief   : 递增顺序搜索树
 * @Link    : https://leetcode-cn.com/problems/increasing-order-search-tree/
 * @Author  : Wei Li
 * @Date    : 2021-08-02
*/

#include <iostream>
#include <vector>

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
    void inorder(TreeNode *node, std::vector<int> &res)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        std::vector<int> res;
        inorder(root, res);

        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *currNode = dummyNode;
        for (int value : res)
        {
            currNode->right = new TreeNode(value);
            currNode = currNode->right;
        }
        return dummyNode->right;
    }
};

// ----------------------------
int main(int argc, char **argv)
{

    return 0;
}
