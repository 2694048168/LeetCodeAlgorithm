/**
 * @File    : treeToDoublyList.cpp
 * @Brief   : 二叉搜索树与双向链表
 * @Link    : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-16
*/

#include <iostream>
#include <utility>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return root;

        std::pair<Node *, Node *> result = findHeadTail(root);

        Node *head = result.first;
        return head;
    }

    std::pair<Node *, Node *> findHeadTail(Node *root)
    {
        Node *leftHead = nullptr, *leftTail = nullptr, *rightHead = nullptr, *rightTail = nullptr;

        std::pair<Node *, Node *> half;

        if (root->left != nullptr)
        {
            half = findHeadTail(root->left);
            leftHead = half.first, leftTail = half.second;
        }
        if (root->right != nullptr)
        {
            half = findHeadTail(root->right);
            rightHead = half.first, rightTail = half.second;
        }

        if (leftHead == nullptr && rightHead == nullptr)
        {
            root->left = root, root->right = root;
            return std::pair<Node *, Node *>(root, root);
        }
        else if (leftHead == nullptr && rightHead != nullptr)
        {
            root->left = rightTail, root->right = rightHead;
            rightHead->left = root, rightTail->right = root;
            return std::pair<Node *, Node *>(root, rightTail);
        }
        else if (leftHead != nullptr && rightHead == nullptr)
        {
            root->left = leftTail, root->right = leftHead;
            leftHead->left = root, leftTail->right = root;
            return std::pair<Node *, Node *>(leftHead, root);
        }
        else
        { //leftHead != nullptr && rightHead != nullptr
            root->left = leftTail, root->right = rightHead;
            leftTail->right = root, leftHead->left = rightTail;
            rightTail->right = leftHead, rightHead->left = root;
            return std::pair<Node *, Node *>(leftHead, rightTail);
        }
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
