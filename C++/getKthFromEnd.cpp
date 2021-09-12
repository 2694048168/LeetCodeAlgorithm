/**
 * @File    : getKthFromEnd.cpp
 * @Brief   : 链表中倒数第k个节点
 * @Link    : https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && k > 0)
        {
            fast = fast->next;
            k--;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // test on leetcode online

    return 0;
}
