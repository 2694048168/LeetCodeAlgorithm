/**
 * @File    : canPlaceFlowers.cpp
 * @Brief   : 种花问题 贪心策略
 * @Link    : https://leetcode-cn.com/problems/can-place-flowers/
 * @Author  : Wei Li
 * @Date    : 2021-07-05
*/

// ------------------
#include <iostream>
#include <vector>
#include <memory>

// -----------------
class Solution
{
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, const unsigned int n)
    {
        // 记录满足条件的最大种植花的数量(贪心策略)
        unsigned int count = 0;
        // -1 表示初始化时候，没有找到任何的已经种了花的位置
        int prev = -1;

        for (size_t i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 1)
            {
                if (prev < 0)
                {
                    // 种植草地数组开始到 i 位置都是 0
                    count += i / 2;
                }
                else
                {
                    count += (i - prev -2) / 2;
                }

                if (count >= n)
                {
                    return true;
                }

                // 更新记录位置索引
                prev = i;
            }
        }
        if (prev < 0)
        {
            // 种植草地数组为空，无论其大小为奇数或者偶数
            count += (flowerbed.size() + 1) / 2;
        }
        else
        {
            // 如果中间某个位置到种植草地数组的末尾都是 0
            count += (flowerbed.size() - prev -1) / 2;
        }
        return count >= n;
    }
};


// ---------------------------------
int main(int argc, char** argv)
{
    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    const unsigned int n = 2;
    // const unsigned int n = 1;

    // auto solution = Solution();
    auto solution = std::make_unique<Solution>();
    // Solution solution;
    // bool placed = solution.canPlaceFlowers(flowerbed, n);
    bool placed = (*solution).canPlaceFlowers(flowerbed, n);
    std::cout << "The solution of this problem is : " << std::boolalpha << placed << std::endl;
    
    return 0;
}