/**
 * @File    : translateNum.cpp
 * @Brief   : 把数字翻译成字符串
 * @Link    : https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-12
*/

#include <iostream>
#include <string>

class Solution
{
public:
    int translateNum(int num)
    {
        std::string src = std::to_string(num);
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i)
        {
            p = q;
            q = r;
            r = 0;
            r += q;
            if (i == 0)
            {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10")
            {
                r += p;
            }
        }
        return r;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    int number = 12258;

    Solution solution;
    auto ways_translate_number = solution.translateNum(number);
    std::cout << "The solution of this problem is " << ways_translate_number << std::endl;

    return 0;
}
