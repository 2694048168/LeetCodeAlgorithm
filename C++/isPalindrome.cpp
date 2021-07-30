/**
 * @File    : isPalindrome.cpp
 * @Brief   : 回文链表
 * @Link    : https://leetcode-cn.com/problems/palindrome-linked-list/
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

// 先使用快慢指针找到链表中点，再把链表切成两半；
// 然后把后半段翻转；最后比较两半是否相等
class Solution
{
public:
    // 主函数
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow)
        {
            if (head->val != slow->val)
            {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    // 辅函数
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *next;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
