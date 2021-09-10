/**
 * @File    : maxProfit2.cpp
 * @Brief   : 股票的最大利润
 * @Link    : https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 * @Author  : Wei Li
 * @Date    : 2021-09-10
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price : prices)
        {
            maxprofit = std::max(maxprofit, price - minprice);
            minprice = std::min(price, minprice);
        }
        return maxprofit;
    }
};

// -------------------------------
int main(int argc, char **argv)
{
    std::vector<int> prices{7,1,5,3,6,4};

    Solution solution;
    auto max_profix = solution.maxProfit(prices);
    std::cout << "The solution of this problem is " << max_profix << std::endl;

    return 0;
}
