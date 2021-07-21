/**
 * @File    : maxProduct.cpp
 * @Brief   : 最大单词长度乘积
 * @Link    : https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
 * @Author  : Wei Li
 * @Date    : 2021-07-21
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxProduct(std::vector<std::string> &words)
    {
        std::unordered_map<int, int> hash;
        int ans = 0;
        for (const std::string &word : words)
        {
            int mask = 0, size = word.size();
            for (const char &c : word)
            {
                mask |= 1 << (c - 'a');
            }
            hash[mask] = std::max(hash[mask], size);
            // for (const auto &[h_mask, h_len] : hash) // c++ 17 结构化绑定
            for (const auto &ha : hash)
            {
                const auto h_mask = ha.first;
                const auto h_len = ha.second;
                if (!(mask & h_mask))
                {
                    ans = std::max(ans, size * h_len);
                }
            }
        }
        return ans;
    }
};

// -----------------------------
int main(int argc, char **argv)
{
    std::vector<std::string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};

    Solution solution;
    auto max_product = solution.maxProduct(words);
    std::cout << "The solutio of this problem is " << max_product << std::endl;

    return 0;
}
