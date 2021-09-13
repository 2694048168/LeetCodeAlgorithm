/**
 * @File    : getIntersectionNode2.cpp
 * @Brief   : 两个链表的第一个公共节点
 * @Link    : https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-13
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
