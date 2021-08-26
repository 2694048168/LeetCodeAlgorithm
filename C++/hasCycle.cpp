/**
 * @File    : hasCycle.cpp
 * @Brief   : 环形链表
 * @Link    : https://leetcode-cn.com/problems/linked-list-cycle/
 * @Author  : Wei Li
 * @Date    : 2021-08-26
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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
