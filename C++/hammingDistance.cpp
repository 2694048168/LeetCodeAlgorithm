/**
 * @File    : hammingDistance.cpp
 * @Brief   : 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目
 * @Link    : https://leetcode-cn.com/problems/hamming-distance/
 * @Author  : Wei Li
 * @Date    : 2021-07-21
*/

#include <iostream>

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int diff_bit = x ^ y, ans = 0;
        while (diff_bit)
        {
            ans += diff_bit & 1;
            diff_bit >>= 1;
        }
        return ans;
    }
};

// Brian Kernighan 算法
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int s = x ^ y, ret = 0;
        while (s)
        {
            s &= s - 1;
            ret++;
        }
        return ret;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    // int x = 1, y = 4;
    // int x = 3, y = 3;
    int x = 3, y = 1;

    Solution solution;
    auto hanming_distance = solution.hammingDistance(x, y);
    std::cout << "The hamming distance of this two integers is " << hanming_distance << std::endl;

    return 0;
}
