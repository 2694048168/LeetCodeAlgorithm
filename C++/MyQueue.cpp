/**
 * @File    : MyQueue.cpp
 * @Brief   : 用栈实现队列
 * @Link    : https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * @Author  : Wei Li
 * @Date    : 2021-07-25
*/

#include <iostream>
#include <stack>

class MyQueue
{
    std::stack<int> in, out;

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x)
    {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        in2out();
        int x = out.top();
        out.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        in2out();
        return out.top();
    }
    void in2out()
    {
        if (out.empty())
        {
            while (!in.empty())
            {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return in.empty() && out.empty();
    }
};

// --------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
