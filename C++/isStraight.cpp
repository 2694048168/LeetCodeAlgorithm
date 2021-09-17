/**
 * @File    : isStraight.cpp
 * @Brief   : 扑克牌中的顺子
 * @Link    : https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-17
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    bool isStraight(std::vector<int> &nums)
    {
        unsigned short note = 0, bit = 1;
        short l = 14, r = -1;
        for (short n : nums)
        {
            if (n == 0)
                continue;
            // 位操作
            // 得到该数字对应的位索引
            bit = 1;
            short move_num = n;
            while (move_num--)
                bit <<= 1;
            // 判断对应位是否为 0，为 0 则代表该数字目前未出现过，并将该位置为 1，
            // 不为 0 则代表出现过直接返回fasle
            if ((note & bit) == 0)
                note ^= bit;
            else
                return false;
            //更新
            if (n < l)
                l = n;
            if (n > r)
                r = n;
        }
        if (r - l + 1 > 5)
            return false;
        return true;
    }
};

// ------------------------------
int main(int argc, char **argv)
{
    // std::vector<int> nums{1, 2, 3, 4, 5};
    std::vector<int> nums{1, 6, 3, 4, 5};

    Solution solution;
    bool check_straight = solution.isStraight(nums);
    std::cout << "The solution of this problem is " << std::boolalpha << check_straight << std::endl;

    return 0;
}
