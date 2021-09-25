/**
 * @File    : lastRemaining.cpp
 * @Brief   : 圆圈中最后剩下的数字
 * @Link    : https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-25
*/

#include <iostream>

class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        int f = 0;
        for (int i = 2; i != n + 1; ++i)
        {
            f = (m + f) % i;
        }
        return f;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    int n = 10;
    int m = 17;
    // int n = 5;
    // int m = 3;

    Solution solution;
    auto last_remaining = solution.lastRemaining(n, m);
    std::cout << "The solution of this problem is " << last_remaining << std::endl;

    return 0;
}
