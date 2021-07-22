/**
 * @File    : findComplement.cpp
 * @Brief   : 数字的补数
 * @Link    : https://leetcode-cn.com/problems/number-complement/
 * @Author  : Wei Li
 * @Date    : 2021-07-22
*/

#include <iostream>

class Solution
{
public:
    int findComplement(int num)
    {
        int m = 1;
        while (m < num)
        {
            m = (m << 1) + 1;
        }
        return m ^ num;
    }
};

// ---------------------------------
int main(int argc, char **argv)
{
    // int number = 5;
    int number = 1;

    Solution solution;
    auto complement_number = solution.findComplement(number);
    std::cout << "The solution of this problem is " << complement_number << std::endl;

    return 0;
}
