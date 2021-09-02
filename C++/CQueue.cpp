/**
 * @File    : CQueue.cpp
 * @Brief   : 用两个栈实现队列
 * @Link    : https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-02
*/

#include <iostream>
#include <stack>

class CQueue
{
    std::stack<int> stack1, stack2;

public:
    CQueue()
    {
        while (!stack1.empty())
        {
            stack1.pop();
        }
        while (!stack2.empty())
        {
            stack2.pop();
        }
    }

    void appendTail(int value)
    {
        stack1.push(value);
    }

    int deleteHead()
    {
        // 如果第二个栈为空
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty())
        {
            return -1;
        }
        else
        {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};

// -----------------------------
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
