/**
 * @File    : frequencySort.cpp
 * @Brief   : 根据字符出现频率排序 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
 * @Link    : https://leetcode-cn.com/problems/sort-characters-by-frequency/
 * @Author  : Wei Li
 * @Date    : 2021-07-10
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
方法二：桶排序
由于每个字符在字符串中出现的频率存在上限，因此可以使用桶排序的思想，根据出现次数生成排序后的字符串。具体做法如下：
1. 遍历字符串，统计每个字符出现的频率，同时记录最高频率 maxFreq
2. 创建桶，存储从 1 到 maxFreq 的每个出现频率的字符；
3. 按照出现频率从大到小的顺序遍历桶，对于每个出现频率，获得对应的字符，然后将每个字符按照出现频率拼接到排序后的字符串。
*/
class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        std::unordered_map<char, int> mp;
        int maxFreq = 0;
        int length = s.size();
        for (auto &ch : s)
        {
            maxFreq = std::max(maxFreq, ++mp[ch]);
        }

        std::vector<std::string> buckets(maxFreq + 1);
        for (auto &num : mp)
        {
            buckets[num.second].push_back(num.first);
        }
        std::string ret;
        for (int i = maxFreq; i > 0; i--)
        {
            std::string &bucket = buckets[i];
            for (auto &ch : bucket)
            {
                for (int k = 0; k < i; k++)
                {
                    ret.push_back(ch);
                }
            }
        }
        return ret;
    }
};

// ----------------------------------
int main(int argc, char **argv)
{
    // std::string str = "tree";
    // std::string str = "cccaaa";
    std::string str = "Aabb";

    auto solution = Solution();
    std::string fre_str = solution.frequencySort(str);
    std::cout << "The solution of this problem is : " << fre_str << std::endl;

    return 0;
}
