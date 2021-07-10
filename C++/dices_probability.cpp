/**
 * @file    : dices_probability.cpp
 * @brief   : n个骰子的点数，动态规划进行算法的设计和分析
 * @link    ：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
 * @author  : Wei Li
 * @date    : 2021-06-30
*/

#include <iostream>
#include <vector>
#include <memory>

class Solution {
public:
    std::vector<double> dicesProbability(int n) 
    {
        // base case n=1
        // std::vector<double> dp = {1.0/6.0, 1.0/6.0, 1.0/6.0, 1.0/6.0, 1.0/6.0, 1.0/6.0};
        // Use the appropriate constructor, which takes a size and a default value.
        // std::vector<int> vec(number_of_elements, default_value);
        const double probability = 1.0 / 6.0;
        std::vector<double> dp(6, probability);

        // 递推式计算
        for (int i = 2; i <= n; ++i)
        {
            // n 增加一次，则求和的不同值类型
            // [1, 6] --> [n, 6n]  ==> size = 6n - n + 1 = 5n + 1
            std::vector<double> temp(5 * i + 1, 0.0);
            // 由马尔科夫链的性质，下一次点数的概率解只与上一次的概率解有关系
            // 遍历上一次的概率解
            for (int j = 0; j < dp.size(); ++j)
            {
                // 每次点数和的变化情况只可能增加 1，2，3，4，5，6
                for (int k = 0; k < 6; ++k)
                {
                    temp[j+k] += dp[j] * probability;
                }
            }
            dp = temp;
        }
        return dp;
    }
};


// 模板
template <typename T>
void DisplayContents(const T& container)
{
  for (auto element = container.cbegin(); element != container.cend(); ++element)
  {
    // std::cout << *element << " ";
    std::cout << *element << std::endl;
  }
  std::cout << std::endl << container.size() << std::endl;
}



int main(int argc, char** argv)
{
    // 骰子的个数 [1, 11]
    const int num_saizi = 1;

    // auto solution = Solution(); 
    // Solution solution;
    auto solution = std::make_unique<Solution>();
    // auto probability_array = solution.dicesProbability(num_saizi);
    auto probability_array = solution->dicesProbability(num_saizi);

    DisplayContents(probability_array);
    
    return 0;
}