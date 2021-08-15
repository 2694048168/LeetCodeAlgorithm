/**
 * @File    : myAtoi.cpp
 * @Brief   : 字符串转换整数 (atoi)
 * @Link    : https://leetcode-cn.com/problems/string-to-integer-atoi/
 * @Author  : Wei Li
 * @Date    : 2021-08-16
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Automaton
{
    std::string state = "start";
    std::unordered_map<std::string, std::vector<std::string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? std::min(ans, (long long)INT_MAX) : std::min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution
{
public:
    int myAtoi(std::string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::string str = "   -42";
    std::string str = "4193 with words";

    Solution solution;
    int atoi_number = solution.myAtoi(str);
    std::cout << "The solution of this problem is " << atoi_number << std::endl;

    return 0;
}
