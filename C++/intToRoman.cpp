/**
 * @File    : intToRoman.cpp
 * @Brief   : 整数转罗马数字
 * @Link    : https://leetcode-cn.com/problems/integer-to-roman/
 * @Author  : Wei Li
 * @Date    : 2021-08-16
*/

#include <iostream>
#include <string>

const std::string thousands[] = {"", "M", "MM", "MMM"};
const std::string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const std::string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const std::string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution
{
public:
    std::string intToRoman(int num)
    {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // int number = 42;
    int number = 1994;

    Solution solution;
    std::string roman_number = solution.intToRoman(number);
    std::cout << "The number " << number << " Roman string is " << roman_number << std::endl;

    return 0;
}
