/**
 * @File    : romanToInt.cpp
 * @Brief   : 罗马数字转整数    
 * @Link    : https://leetcode-cn.com/problems/roman-to-integer/    
 * @Author  : Wei Li
 * @Date    : 2021-08-15
*/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int romanToInt(std::string str)
    {
        int answer = 0;
        int length_string = str.length();
        for (size_t i = 0; i < length_string; ++i)
        {
            int value = symbolValues[str[i]];
            if (i < length_string - 1 && value < symbolValues[str[i + 1]])
            {
                answer -= value;
            }
            else
            {
                answer += value;
            }
        }

        return answer;
    }

private:
    std::unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};

// -----------------------------
int main(int argc, char **argv)
{
    // std::string str_roman = "MCMXCIV";
    std::string str_roman = "IX";

    Solution solution;
    int roman_int_number = solution.romanToInt(str_roman);
    std::cout << "The roman of string " << str_roman << " is number of int : " << roman_int_number << std::endl;

    return 0;
}
