/**
 * @File    : calculate.cpp
 * @Brief   : 基本计算器 II
 * @Link    : https://leetcode-cn.com/problems/basic-calculator-ii/
 * @Author  : Wei Li
 * @Date    : 2021-07-28
*/

#include <iostream>
#include <string>

class Solution
{
public:
    // 主函数
    int calculate(std::string s)
    {
        int i = 0;
        return parseExpr(s, i);
    }
    // 辅函数 - 递归parse从位置i开始的剩余字符串
    int parseExpr(const std::string &s, int &i)
    {
        char op = '+';
        long left = 0, right = 0;
        while (i < s.length())
        {
            if (s[i] != ' ')
            {
                long n = parseNum(s, i);
                switch (op)
                {
                case '+':
                    left += right;
                    right = n;
                    break;
                case '-':
                    left += right;
                    right = -n;
                    break;
                case '*':
                    right *= n;
                    break;
                case '/':
                    right /= n;
                    break;
                }
                if (i < s.length())
                {
                    op = s[i];
                }
            }
            ++i;
        }
        return left + right;
    }
    // 辅函数 - parse从位置i开始的一个数字
    long parseNum(const std::string &s, int &i)
    {
        long n = 0;
        while (i < s.length() && isdigit(s[i]))
        {
            n = 10 * n + (s[i++] - '0');
        }
        return n;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string str = "3+2*2";

    Solution solution;
    auto calculate_value = solution.calculate(str);
    std::cout << "The solution of this problem is " << calculate_value << std::endl;

    return 0;
}
