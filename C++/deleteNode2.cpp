/**
 * @File    : deleteNode2.cpp
 * @Brief   : 删除链表的节点
 * @Link    : https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-12
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head->val == val)
            return head->next;
        ListNode *pre = head, *cur = head->next;
        while (cur != nullptr && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur != nullptr)
            pre->next = cur->next;
        return head;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
