/**
 * @File    : addStrings.cpp
 * @Brief   : 字符串相加 数学问题
 * @Link    : https://leetcode-cn.com/problems/add-strings/
 * @Author  : Wei Li
 * @Date    : 2021-07-18
*/

#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::string addStrings(std::string num1, std::string num2)
    {
        std::string output("");
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        int onelen = num1.length(), twolen = num2.length();
        if (onelen <= twolen)
        {
            std::swap(num1, num2);
            std::swap(onelen, twolen);
        }
        int addbit = 0;
        for (int i = 0; i < twolen; ++i)
        {
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
            output += std::to_string((cur_sum) % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        for (int i = twolen; i < onelen; ++i)
        {
            int cur_sum = (num1[i] - '0') + addbit;
            output += std::to_string((cur_sum) % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        if (addbit)
        {
            output += "1";
        }
        std::reverse(output.begin(), output.end());
        return output;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::string num1 = "99", num2 = "1";

    Solution solution;
    auto sum_str = solution.addStrings(num1, num2);
    std::cout << "The solution of this problem is " << sum_str << std::endl;

    return 0;
}
