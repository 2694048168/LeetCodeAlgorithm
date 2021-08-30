/**
 * @File    : findNumOfValidWords.cpp
 * @Brief   : 猜字谜
 * @Link    : https://leetcode-cn.com/problems/number-of-valid-words-for-each-puzzle/
 * @Author  : Wei Li
 * @Date    : 2021-08-30
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution
{
public:
    std::vector<int> findNumOfValidWords(std::vector<std::string> &words, std::vector<std::string> &puzzles)
    {
        std::unordered_map<int, int> frequency;

        for (const std::string &word : words)
        {
            int mask = 0;
            for (char ch : word)
            {
                mask |= (1 << (ch - 'a'));
            }
            if (__builtin_popcount(mask) <= 7)
            {
                ++frequency[mask];
            }
        }

        std::vector<int> ans;
        for (const std::string &puzzle : puzzles)
        {
            int total = 0;

            // 枚举子集方法一
            // for (int choose = 0; choose < (1 << 6); ++choose) {
            //     int mask = 0;
            //     for (int i = 0; i < 6; ++i) {
            //         if (choose & (1 << i)) {
            //             mask |= (1 << (puzzle[i + 1] - 'a'));
            //         }
            //     }
            //     mask |= (1 << (puzzle[0] - 'a'));
            //     if (frequency.count(mask)) {
            //         total += frequency[mask];
            //     }
            // }

            // 枚举子集方法二
            int mask = 0;
            for (int i = 1; i < 7; ++i)
            {
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask;
            do
            {
                int s = subset | (1 << (puzzle[0] - 'a'));
                if (frequency.count(s))
                {
                    total += frequency[s];
                }
                subset = (subset - 1) & mask;
            } while (subset != mask);

            ans.push_back(total);
        }
        return ans;
    }
};

template <typename T>
void DispalyElement(const T &container)
{
    for (auto element : container)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// ------------------------------
int main(int argc, char **argv)
{
    std::vector<std::string> words{"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    std::vector<std::string> puzzles{"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};

    Solution solution;
    auto find_number_valid_words = solution.findNumOfValidWords(words, puzzles);
    DispalyElement(find_number_valid_words);

    return 0;
}
