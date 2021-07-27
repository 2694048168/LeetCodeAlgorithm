/**
 * @File    : MyStack.cpp
 * @Brief   : 用队列实现栈
 * @Link    : https://leetcode-cn.com/problems/implement-stack-using-queues/
 * @Author  : Wei Li
 * @Date    : 2021-07-27
*/

#include <iostream>
#include <queue>

class MyStack
{
public:
    std::queue<int> q;

    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int r = q.front();
        q.pop();
        return r;
    }

    /** Get the top element. */
    int top()
    {
        int r = q.front();
        return r;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
