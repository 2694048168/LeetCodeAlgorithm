/**
 * @File    : getRandom.cpp
 * @Brief   : 链表随机节点
 * @Link    : https://leetcode-cn.com/problems/linked-list-random-node/
 * @Author  : Wei Li
 * @Date    : 2021-07-19
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *n) : head(n) {}

    /** Returns a random node's value. */
    int getRandom()
    {
        int ans = head->val;
        ListNode *node = head->next;
        int i = 2;
        while (node)
        {
            if ((rand() % i) == 0)
            {
                ans = node->val;
            }
            ++i;
            node = node->next;
        }
        return ans;
    }

private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main(int argc, char **argv)
{
    // test on LeetCode inline.

    return 0;
}
