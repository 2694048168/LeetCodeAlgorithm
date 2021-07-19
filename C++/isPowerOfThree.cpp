/**
 * @File    : isPowerOfThree.cpp
 * @Brief   : 3的幂 数学问题 
 * @Link    : https://leetcode-cn.com/problems/power-of-three/
 * @Author  : Wei Li
 * @Date    : 2021-07-19
*/

#include <iostream>
#include <cmath>

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // <cmath> std::fmod(x, y) 计算除法运算 x / y 后的浮点形式的余数
        // log_base(3)_(n) 通过换底公式进行计算
        return std::fmod(log10(n) / log10(3), 1) == 0;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // int num = 21;
    int num = 27;

    Solution solution;
    auto check_power_three = solution.isPowerOfThree(num);
    std::cout << "The solution of this problem is " << std::boolalpha << check_power_three << std::endl;

    return 0;
}
