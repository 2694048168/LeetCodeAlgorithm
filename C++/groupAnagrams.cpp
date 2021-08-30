/**
 * @File    : groupAnagrams.cpp
 * @Brief   : 字母异位词分组
 * @Link    : https://leetcode-cn.com/problems/group-anagrams/
 * @Author  : Wei Li
 * @Date    : 2021-08-30
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <numeric>
#include <array>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = std::hash<int>{}](const std::array<int, 26> &arr) -> size_t
        {
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num)
                                   { return (acc << 1) ^ fn(num); });
        };

        std::unordered_map<std::array<int, 26>, std::vector<std::string>, decltype(arrayHash)> mp(0, arrayHash);
        for (std::string &str : strs)
        {
            std::array<int, 26> counts{};
            int length = str.length();
            for (int i = 0; i < length; ++i)
            {
                counts[str[i] - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

template <typename T>
void DisplayElement(const T &container)
{
    for (auto element : container)
    {
        for (auto value : element)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solution;
    auto group_anagram = solution.groupAnagrams(strs);
    DisplayElement(group_anagram);

    return 0;
}
