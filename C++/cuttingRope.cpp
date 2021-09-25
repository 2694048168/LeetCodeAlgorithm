/**
 * @File    : cuttingRope.cpp
 * @Brief   : 剪绳子
 * @Link    : https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-25
*/

#include <iostream>
#include <cmath>

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 4)
            return n - 1;
        int count_3 = n / 3;
        if (n - 3 * count_3 == 1)
        {
            count_3--;
        }
        int count_2 = (n - 3 * count_3) / 2;
        return ((int)std::pow(3, count_3) * (int)std::pow(2, count_2));
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int n = 10;

    Solution solution;
    auto cutting_rose = solution.cuttingRope(n);
    std::cout << "The solution of this problem is " << cutting_rose << std::endl;

    return 0;
}
