/**
 * @File    : trailingZeroes.cpp
 * @Brief   : 阶乘后的零 数学问题
 * @Link    : https://leetcode-cn.com/problems/factorial-trailing-zeroes/
 * @Author  : Wei Li
 * @Date    : 2021-07-18
*/

#include <iostream>

class Solution
{
public:
    int trailingZeroes(int n)
    {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    int num = 12;

    Solution solution;
    auto num_zeros = solution.trailingZeroes(num);
    std::cout << "The solution of this problem is " << num_zeros << std::endl;

    return 0;
}
