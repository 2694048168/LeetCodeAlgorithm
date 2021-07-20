/**
 * @File    : addBinary.cpp
 * @Brief   : 二进制求和
 * @Link    : https://leetcode-cn.com/problems/add-binary/
 * @Author  : Wei Li
 * @Date    : 2021-07-20
*/

#include <iostream>
#include <string>
#include <algorithm>


// 模拟计算方式
class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string ans;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        int n = std::max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i)
        {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::string a = "11", b = "1";
    std::string a = "1010", b = "1011";

    Solution  solution;
    std::string add_binary = solution.addBinary(a, b);
    std::cout << "The solution of this problem is " << add_binary << std::endl;

    return 0;
}
