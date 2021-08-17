/**
 * @File    : isNumber.cpp
 * @Brief   : 有效数字
 * @Link    : https://leetcode-cn.com/problems/valid-number/
 * @Author  : Wei Li
 * @Date    : 2021-08-17
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
        else
        {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(std::string s)
    {
        std::unordered_map<State, std::unordered_map<CharType, State>> transfer{
            {STATE_INITIAL, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}, {CHAR_SIGN, STATE_INT_SIGN}}}, {STATE_INT_SIGN, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}}, {STATE_INTEGER, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_EXP, STATE_EXP}, {CHAR_POINT, STATE_POINT}}}, {STATE_POINT, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}}}, {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_FRACTION}}}, {STATE_FRACTION, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}}}, {STATE_EXP, {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SIGN, STATE_EXP_SIGN}}}, {STATE_EXP_SIGN, {{CHAR_NUMBER, STATE_EXP_NUMBER}}}, {STATE_EXP_NUMBER, {{CHAR_NUMBER, STATE_EXP_NUMBER}}}};

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
    bool isInt(std::string s)
    {
        if (s.empty())
            return false;
        int i = 0;
        if (s[i] == '+' || s[i] == '-')
            i++;
        if (i == s.size())
            return false;
        while (i < s.size())
        {
            if (!(s[i] >= '0' && s[i] <= '9'))
                return false;
            i++;
        }
        return true;
    }
    bool isNumber(std::string s)
    {
        int i = 0;
        if (s[i] == '+' || s[i] == '-')
            i++;
        if (s[i] == 'e' || s[i] == 'E')
            return false;
        if (s[i] == '.' && (i + 1 == s.size() || !(s[i + 1] >= '0' && s[i + 1] <= '9')))
            return false;
        int dot = 0, e = 0;
        while (i < s.size())
        {
            if (s[i] >= '0' && s[i] <= '9')
                ;
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (e)
                    return false;
                e = 1;
                return isInt(s.substr(i + 1));
            }
            else if (s[i] == '.')
            {
                if (dot || e)
                    return false;
                dot = 1;
                // if(i + 1 == s.size()) return false;
            }
            else
                return false;
            i++;
        }
        return true;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string str = ".1";
    // std::string str = "e";

    Solution solution;
    bool is_valid_number = solution.isNumber(str);
    std::cout << "The solution of this problem is " << std::boolalpha << is_valid_number << std::endl;

    return 0;
}
