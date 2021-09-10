/**
 * @File    : fib.cpp
 * @Brief   : 斐波那契数列
 * @Link    : https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-10
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    const int MOD = 1000000007;

    int fib(int n)
    {
        if (n < 2)
        {
            return n;
        }
        std::vector<std::vector<long>> q{{1, 1}, {1, 0}};
        std::vector<std::vector<long>> res = pow(q, n - 1);
        return res[0][0];
    }

    std::vector<std::vector<long>> pow(std::vector<std::vector<long>> &a, int n)
    {
        std::vector<std::vector<long>> ret{{1, 0}, {0, 1}};
        while (n > 0)
        {
            if (n & 1)
            {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    std::vector<std::vector<long>> multiply(std::vector<std::vector<long>> &a, std::vector<std::vector<long>> &b)
    {
        std::vector<std::vector<long>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
            }
        }
        return c;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int n = 5;

    Solution solution;
    auto fib_number = solution.fib(n);
    std::cout << "The solution of this problem is " << fib_number << std::endl;

    return 0;
}
