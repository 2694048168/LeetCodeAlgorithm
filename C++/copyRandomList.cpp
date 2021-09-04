/**
 * @File    : copyRandomList.cpp
 * @Brief   : 复杂链表的复制
 * @Link    : https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-04
*/

#include <iostream>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node *headNew = head->next;
        for (Node *node = head; node != nullptr; node = node->next)
        {
            Node *nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
