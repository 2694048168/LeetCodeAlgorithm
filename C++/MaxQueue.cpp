/**
 * @File    : MaxQueue.cpp
 * @Brief   : 队列的最大值
 * @Link    : https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-28
*/

#include <iostream>
#include <queue>
#include <deque>

class MaxQueue
{
    std::queue<int> q;
    std::deque<int> d;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (d.empty())
            return -1;
        return d.front();
    }

    void push_back(int value)
    {
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front())
        {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
// ----------------------------
int main(int argc, char **argv)
{
    // test on leetcode online.

    return 0;
}
