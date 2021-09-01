/**
 * @File    : maxPathSum.cpp
 * @Brief   : 二叉树中的最大路径和
 * @Link    : https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
 * @Author  : Wei Li
 * @Date    : 2021-09-01
*/

#include <iostream>
#include <algorithm>

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
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = std::max(maxGain(node->left), 0);
        int rightGain = std::max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = std::max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + std::max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode *root)
    {
        maxGain(root);
        return maxSum;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode onlone.

    return 0;
}
