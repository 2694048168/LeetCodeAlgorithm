/**
 * @File    : addAlgorithm.cpp
 * @Brief   : 不用加减乘除做加法
 * @Link    : https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-22
*/

#include <iostream>

class Solution2
{
public:
    int add(int a, int b)
    {
        while (b)
        {
            int Sumof_noJinWei = a ^ b; //a异或b为无进位求和
            //a & b后哪个位上是1，则该位相加会产生进位，而进位是左移后的结果。为保险我们强制转换为无符号整型
            int jinWei = (unsigned int)(a & b) << 1;

            a = Sumof_noJinWei;
            b = jinWei; //直到没有进位了，得到结果
        }
        return a;
    }
};

class Solution
{
public:
    int add(int a, int b)
    {
        // 后续用a表示非进位和，b表示进位，当进位为0，则表示计算结束
        return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1);
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    int a = 1, b = 1;

    Solution solution;
    auto result_add = solution.add(a, b);
    std::cout << "The solution of this problem is " << result_add << std::endl;

    return 0;
}
