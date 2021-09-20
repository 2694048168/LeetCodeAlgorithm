/**
 * @File    : sumNums.cpp
 * @Brief   : 求1+2+…+n
 * @Link    : https://leetcode-cn.com/problems/qiu-12n-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-20
*/

#include <iostream>

class Solution
{
public:
    int sumNums(int n)
    {
        int ans = 0, A = n, B = n + 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        (B & 1) && (ans += A);
        A <<= 1;
        B >>= 1;

        return ans >> 1;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // int number = 9;
    // int number = 6;
    int number = 3;

    Solution solution;
    auto sum_number = solution.sumNums(number);
    std::cout << "The solution of this problem is " << sum_number << std::endl;

    return 0;
}
