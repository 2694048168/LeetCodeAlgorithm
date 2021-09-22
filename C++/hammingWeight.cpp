/**
 * @File    : hammingWeight.cpp
 * @Brief   : 二进制中1的个数
 * @Link    : https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-22
*/

#include <iostream>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        while (n)
        {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // uint32_t number = 11;
    // uint32_t number = 128;
    uint32_t number = 4294967293;

    Solution solution;
    auto hamming_weight = solution.hammingWeight(number);
    std::cout << "The solution of this problem is " << hamming_weight << std::endl;

    return 0;
}
