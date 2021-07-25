/**
 * @File    : isValid.cpp
 * @Brief   : 有效的括号
 * @Link    : https://leetcode-cn.com/problems/valid-parentheses/
 * @Author  : Wei Li
 * @Date    : 2021-07-25
*/

#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> parsed;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                parsed.push(s[i]);
            }
            else
            {
                if (parsed.empty())
                {
                    return false;
                }
                char c = parsed.top();
                if ((s[i] == '}' && c == '{') ||
                    (s[i] == ']' && c == '[') ||
                    (s[i] == ')' && c == '('))
                {
                    parsed.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return parsed.empty();
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::string str = "()";
    std::string str = "([)]";

    Solution solution;
    bool check_valid = solution.isValid(str);
    std::cout << "The solution of this problem is " << std::boolalpha << check_valid << std::endl;

    return 0;
}
