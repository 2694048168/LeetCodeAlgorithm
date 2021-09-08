/**
 * @File    : isSymmetricTree.cpp
 * @Brief   : 对称的二叉树
 * @Link    : https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-08
*/

#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        std::queue<TreeNode *> que;
        que.push(root->left);  // 将左子树头结点加入队列
        que.push(root->right); // 将右子树头结点加入队列
        while (!que.empty())
        { // 接下来就要判断这这两个树是否相互翻转
            TreeNode *leftNode = que.front();
            que.pop();
            TreeNode *rightNode = que.front();
            que.pop();
            if (!leftNode && !rightNode)
            { // 左节点为空、右节点为空，此时说明是对称的
                continue;
            }

            // 左右一个节点不为空，或者都不为空但数值不相同，返回false
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val)))
            {
                return false;
            }
            que.push(leftNode->left);   // 加入左节点左孩子
            que.push(rightNode->right); // 加入右节点右孩子
            que.push(leftNode->right);  // 加入左节点右孩子
            que.push(rightNode->left);  // 加入右节点左孩子
        }
        return true;
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
