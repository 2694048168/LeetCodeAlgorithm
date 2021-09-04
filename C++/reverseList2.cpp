/**
 * @File    : reverseList2.cpp
 * @Brief   : 反转链表
 * @Link    : https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-04
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
