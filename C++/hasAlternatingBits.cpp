/**
 * @File    : hasAlternatingBits.cpp
 * @Brief   : 交替位二进制数
 * @Link    : https://leetcode-cn.com/problems/binary-number-with-alternating-bits/
 * @Author  : Wei Li
 * @Date    : 2021-07-22
*/

#include <iostream>

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        bool a = false;
        while (n != 0)
        {
            if (((n & 1) ^ (n >> 1) & 1) == 0)
            {
                a = false;
                break;
            }
            else
                a = true;
            n = n >> 1;
        }
        return a;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // int number = 5;
    int number = 7;

    Solution solution;
    bool check_alternate_bits = solution.hasAlternatingBits(number);
    std::cout << "The solution of this problem is " << std::boolalpha << check_alternate_bits << std::endl;

    return 0;
}
