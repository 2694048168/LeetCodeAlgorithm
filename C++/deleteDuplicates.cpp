/**
 * @File    : deleteDuplicates.cpp
 * @Brief   : 删除排序链表中的重复元素
 * @Link    : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return head;
        }

        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }

        return head;
    }
};

// ------------------------------
int main(int argc, char **argv)
{

    return 0;
}
