/**
 * @File    : isSubStructure.cpp
 * @Brief   : 树的子结构
 * @Link    : https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-08
*/

#include <iostream>

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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        return (A && B) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool recur(TreeNode *A, TreeNode *B)
    {
        if (!B)
            return true;
        if (!A || A->val != B->val)
            return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
