/**
 * @File    : isNumberStr.cpp
 * @Brief   : 表示数值的字符串
 * @Link    : https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-27
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution2
{
public:
    enum State
    {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch)
    {
        if (ch >= '0' && ch <= '9')
        {
            return CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E')
        {
            return CHAR_EXP;
        }
        else if (ch == '.')
        {
            return CHAR_POINT;
        }
        else if (ch == '+' || ch == '-')
        {
            return CHAR_SIGN;
        }
        else if (ch == ' ')
        {
            return CHAR_SPACE;
        }
        else
        {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(std::string s)
    {
        std::unordered_map<State, std::unordered_map<CharType, State>> transfer{
            {STATE_INITIAL, {{CHAR_SPACE, STATE_INITIAL}, {CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}, {CHAR_SIGN, STATE_INT_SIGN}}}, {STATE_INT_SIGN, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}}, {STATE_INTEGER, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_EXP, STATE_EXP}, {CHAR_POINT, STATE_POINT}, {CHAR_SPACE, STATE_END}}}, {STATE_POINT, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}, {CHAR_SPACE, STATE_END}}}, {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_FRACTION}}}, {STATE_FRACTION, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}, {CHAR_SPACE, STATE_END}}}, {STATE_EXP, {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SIGN, STATE_EXP_SIGN}}}, {STATE_EXP_SIGN, {{CHAR_NUMBER, STATE_EXP_NUMBER}}}, {STATE_EXP_NUMBER, {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SPACE, STATE_END}}}, {STATE_END, {{CHAR_SPACE, STATE_END}}}};

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++)
        {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end())
            {
                return false;
            }
            else
            {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};

class Solution
{
public:
    bool isNumber(std::string s)
    {
        if (s.size() < 1)
            return false;
        int i = 0;
        // 越过头部空格
        while (s[i] == ' ')
            ++i;
        // 扫描数字，带符号或不带符号都行
        bool numeric = scanInteger(s, i);

        // 如果出现'.'，则接下来是数字的小数部分
        if (s[i] == '.')
        {
            ++i;
            // 1.小数可以没有整数部分，如.123
            // 2.小数点后面可以没有数字，如233.
            // 3.小数点前后可以都有数字
            numeric = scanUnsignedInteger(s, i) || numeric;
        }

        // 如果出现'e'或者'E'，则接下来是数字的指数部分
        if (s[i] == 'e' || s[i] == 'E')
        {
            ++i;
            // 用&&的原因：
            // 1.当e或E前面没有数字时，整个字符串不能表示数字，如.e1、e1;
            // 2.当e或E后面没有整数时，整个字符串不能表示数字，如12e，12e+5.4
            numeric = numeric && scanInteger(s, i);
        }
        // 扫描尾后空格
        while (s[i] == ' ')
            ++i;

        return numeric && i == s.size();
    }

private:
    bool scanUnsignedInteger(const std::string &s, int &i)
    {
        int pos = i;
        while (s[i] != s.size() && s[i] >= '0' && s[i] <= '9')
            ++i;
        // 当s中存在若干0~9数字时，返回true
        return i > pos;
    }

    bool scanInteger(const std::string &s, int &i)
    {
        if (s[i] == '+' || s[i] == '-')
            ++i;
        return scanUnsignedInteger(s, i);
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string str = "    .1  ";

    Solution solution;
    bool check_number = solution.isNumber(str);
    std::cout << "The solution of this problem is " << std::boolalpha << check_number << std::endl;

    return 0;
}
