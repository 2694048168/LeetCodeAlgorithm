/**
 * @File    : MinStack2.cpp
 * @Brief   : 包含min函数的栈  
 * @Link    : https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-02
*/

#include <iostream>
#include <stack>

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        _min.push(INT_MAX);
    }

    void push(int x)
    {
        st.push(x);
        if (x <= _min.top())
        {
            _min.push(x);
        }
    }

    void pop()
    {
        if (st.top() == _min.top())
            _min.pop();
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int min()
    {
        return _min.top();
    }

private:
    std::stack<int> st;
    std::stack<int> _min;
};

// -----------------------------
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
