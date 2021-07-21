/**
 * @File    : isPowerOfFour.cpp
 * @Brief   : 4的幂
 * @Link    : https://leetcode-cn.com/problems/power-of-four/
 * @Author  : Wei Li
 * @Date    : 2021-07-21
*/

#include <iostream>

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && !(n & (n - 1)) && (n & 1431655765);
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // int number = 16;
    int number = 5;

    Solution solution;
    bool check_power_four = solution.isPowerOfFour(number);
    std::cout << "The solution of this problem is " << std::boolalpha << check_power_four << std::endl;

    return 0;
}
