/**
 * @File    : convertToBase7.cpp
 * @Brief   : 七进制数 数学问题
 * @Link    : https://leetcode-cn.com/problems/base-7/
 * @Author  : Wei Li
 * @Date    : 2021-07-18
*/

#include <iostream>
#include <string>

class Solution
{
public:
    std::string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }

        bool is_negative = num < 0;
        if (is_negative)
        {
            num = -num;
        }
        std::string ans;
        while (num)
        {
            int a = num / 7, b = num % 7;
            ans = std::to_string(b) + ans;
            num = a;
        }
        return is_negative ? "-" + ans : ans;
    }
};

// ----------------------------
int main(int argc, char **argv)
{
    // int num = 100;
    int num = -7;

    Solution solution;
    auto base_num = solution.convertToBase7(num);
    std::cout << "The solution of this problem is " << base_num << std::endl;

    return 0;
}
