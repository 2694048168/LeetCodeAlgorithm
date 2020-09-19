/**
 * LeetCodeLink ： https://leetcode-cn.com/problems/regular-expression-matching
 * 
 * 10. 正则表达式匹配
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖整个字符串 s 的，而不是部分字符串。
 * 
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。
 *      因此，字符串 "aa" 可被视为 'a' 重复了一次。
 */

/**
 * 动态规划的一般流程三步：暴力的递归解法 -> 带备忘录的递归解法 -> 迭代的动态规划解法
 * 思考流程来说， 就分为步骤：找到状态和选择 -> 明确 dp 数组/函数的定义 -> 寻找状态之间的关系
 * 
 * 这就是思维模式的框架，按照以上的模式来解决问题，养成这种模式思维
 */


//![include]
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
//![include]

//![solution]

/**
 * 动态规划 = 状态转移方程 + 边界条件
 * 
 * 状态转移方程 = f[i][j] = 
 * if(p[j] != '*') = f[i-1][j-1] matches; otherwise false;
 * otherwise = f[i-1][j] or f[i][j-2] matches; otherwise f[i][j-2] 
 * 边界条件 = f[0][0] = true, 即就是空串可以匹配
 * 
 * 逐步匹配、 S.size = m、 P.size = n
 * 时间复杂度 T(n) = big O(mn)
 * 空间复杂度 S(n) = big O(mn)
 */
class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int m = s.size();
        int n = p.size();

        /**
         * C-Plus-Plus/C++/CPP Programming Paradigm 编程范式
         * 1、Structural Programming 结构化编程 ——> 面向过程编程
         * 2、Object-Oriented Programming 面向对象编程 OOP
         * 3、Generic Programming 泛型编程 GP
         * 4、Functional Programming 函数式编程 FP Lamda表达式
         */
        // matches(x,y) 判断两个字符是否匹配的辅助函数
        //只有当 y 是 . 或者 x 和 y 本身相同时，这两个字符才会匹配
        // [&] 引用捕获，C++11 新特性，lamda 表达式
        auto matches = [&](int i, int j)
        {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        //![动态规划 ][Dynamic programming]
        // 状态方程
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        // 边界条件
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (p[j - 1] == '*') 
                {
                    // 逻辑运算符：&& || !
                    // 二进制位操作符 或 运算符 |
                    // 二进制位操作符 异或 运算符 ^
                    // 二进制位操作符 取反 运算符 ~
                    // 二进制位操作符 左移运算符 <<
                    // 二进制位操作符 右移运算符 >>
                    // 无符号右移运算符 >>>
                    // |= 复合赋值运算符 
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) 
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else 
                {
                    if (matches(i, j)) 
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
        //![动态规划 ][Dynamic programming]
    }
};
//![solution]

/**
 * @function Main function
 */
int main(int argc, char **argv)
{
    //![test]
    string s = "aa";
    // string p = "a";
    // string p = "a.";
    string p = "a*";
    Solution solution;
    std::cout << std::boolalpha << solution.isMatch(s, p) << std::endl;

    return 0;
}

