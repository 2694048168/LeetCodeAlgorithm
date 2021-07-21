/**
 * @File    : reverseBits.cpp
 * @Brief   : 颠倒给定的 32 位无符号整数的二进制位
 * @Link    : https://leetcode-cn.com/problems/reverse-bits/
 * @Author  : Wei Li
 * @Date    : 2021-07-21
*/

#include <iostream>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (size_t i = 0; i < 32; ++i)
        {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    uint32_t number = 43261596;

    Solution solution;
    uint32_t reverse_bits = solution.reverseBits(number);
    std::cout << "The origin number is " << number << std::endl;
    std::cout << "The binary reverse number is " << reverse_bits << std::endl;

    return 0;
}
