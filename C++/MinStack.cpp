/**
 * @File    : MinStack.cpp
 * @Brief   : 最小栈
 * @Link    : https://leetcode-cn.com/problems/min-stack/
 * @Author  : Wei Li
 * @Date    : 2021-07-25
*/

#include <iostream>
#include <stack>

class MinStack
{
    std::stack<int> s, min_s;

public:
    MinStack() {}
    void push(int x)
    {
        s.push(x);
        if (min_s.empty() || min_s.top() >= x)
        {
            min_s.push(x);
        }
    }
    void pop()
    {
        if (!min_s.empty() && min_s.top() == s.top())
        {
            min_s.pop();
        }
        s.pop();
    }
    int top()
    {
        return s.top();
    }
    int getMin()
    {
        return min_s.top();
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // test on LeetCode online.

    return 0;
}
