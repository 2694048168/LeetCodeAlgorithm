/**
 * @File    : sortedListToBST.cpp
 * @Brief   : 有序链表转换二叉搜索树
 * @Link    : https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * @Author  : Wei Li
 * @Date    : 2021-08-02
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode *getMedian(ListNode *left, ListNode *right)
    {
        ListNode *fast = left;
        ListNode *slow = left;
        while (fast != right && fast->next != right)
        {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode *buildTree(ListNode *left, ListNode *right)
    {
        if (left == right)
        {
            return nullptr;
        }
        ListNode *mid = getMedian(left, right);
        TreeNode *root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        return buildTree(head, nullptr);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
