/**
 * @File    : myPow.cpp
 * @Brief   : 数值的整数次方
 * @Link    : https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-21
*/

#include <iostream>

class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1.0;
        // 考虑边缘情况
        if (x == 0 || x == 1.0)
        {
            return x;
        }

        // 考虑溢出的情况
        long b = (long)n;
        if (b < 0)
        {
            b = -b;
            x = 1 / x;
        }

        while (b > 0)
        {
            if ((b & 1) == 1)
            {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }

        return res;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    double x = 2.00000;
    int n = 10;

    Solution solution;
    auto my_pow = solution.myPow(x, n);
    std::cout << "The solution of this problem is " << my_pow << std::endl;

    return 0;
}
