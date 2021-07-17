/**
 * @File    : diffWaysToCompute.cpp
 * @Brief   : 为运算表达式设计优先级 分治算法策略
 * @Link    : https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
 * @Author  : Wei Li
 * @Date    : 2021-07-17
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Solution2
{
public:
    std::vector<int> diffWaysToCompute(std::string expression)
    {
        std::vector<int> ways;
        for (size_t i = 0; i < expression.length(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                std::vector<int> lefts = diffWaysToCompute(expression.substr(0, i));
                std::vector<int> rights = diffWaysToCompute(expression.substr(i + 1));
                for (const int &left : lefts)
                {
                    for (const int &right : rights)
                    {
                        switch (c)
                        {
                        case '+':
                            ways.push_back(left + right);
                            break;
                        case '-':
                            ways.push_back(left - right);
                            break;
                        case '*':
                            ways.push_back(left * right);
                            break;

                        default:
                            break;
                        }
                    }
                }
            }
        }
        // bound condation
        if (ways.empty())
        {
            // 没有运算符，直接舍弃所有空白字符
            ways.push_back(std::stoi(expression));
        }

        return ways;
    }
};

class Solution
{
public:
    std::vector<int> diffWaysToCompute(std::string input)
    {
        std::vector<int> data;
        std::vector<char> ops;
        int num = 0;
        char op = ' ';
        std::istringstream ss(input + "+");
        while (ss >> num && ss >> op)
        {
            data.push_back(num);
            ops.push_back(op);
        }
        int n = data.size();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>()));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (i == j)
                {
                    dp[j][i].push_back(data[i]);
                }
                else
                {
                    for (int k = j; k < i; k += 1)
                    {
                        for (auto left : dp[j][k])
                        {
                            for (auto right : dp[k + 1][i])
                            {
                                int val = 0;
                                switch (ops[k])
                                {
                                case '+':
                                    val = left + right;
                                    break;
                                case '-':
                                    val = left - right;
                                    break;
                                case '*':
                                    val = left * right;
                                    break;
                                }
                                dp[j][i].push_back(val);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};


template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    // std::string expression = "2-1-1";
    std::string expression = "2*3-4*5";

    Solution solution;
    auto calc_results = solution.diffWaysToCompute(expression);
    std::cout << "The solution of this problem is " << std::endl;
    DisplayElement(calc_results);

    return 0;
}
