/**
 * @File    : swapPairs.cpp
 * @Brief   : 两两交换链表中的节点
 * @Link    : https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * @Author  : Wei Li
 * @Date    : 2021-07-30
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

// 利用指针进行交换操作
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *p = head, *s;
        if (p && p->next)
        {
            s = p->next;
            p->next = s->next;
            s->next = p;
            head = s;
            while (p->next && p->next->next)
            {
                s = p->next->next;
                p->next->next = s->next;
                s->next = p->next;
                p->next = s;
                p = s->next;
            }
        }
        return head;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
