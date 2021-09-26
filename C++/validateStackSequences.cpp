/**
 * @File    : validateStackSequences.cpp
 * @Brief   : 栈的压入、弹出序列
 * @Link    : https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-26
*/

#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
    bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped)
    {
        std::stack<int> s;
        int p1 = 0, p2 = 0;
        int pushsize = pushed.size();
        int popsize = popped.size();
        while (p1 < pushsize)
        {
            s.push(pushed[p1]);
            ++p1;
            while (!s.empty() && s.top() == popped[p2])
            {
                s.pop();
                ++p2;
            }
        }
        return s.empty();
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<int> pushed{1,2,3,4,5};
    std::vector<int> popped{4,5,3,2,1};

    Solution solution;
    bool valid_stack_seq = solution.validateStackSequences(pushed, popped);
    std::cout << "The solution of this problem is " << std::boolalpha << valid_stack_seq << std::endl;

    return 0;
}
