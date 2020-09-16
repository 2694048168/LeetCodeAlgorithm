/*
** LeetCodeLink: https://leetcode-cn.com/problems/two-sum/
**
** 1. 两数之和
** 给定一个整数数组 nums 和一个目标值 target，
** 请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
** 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
**
** 示例:
** 给定 nums = [2, 7, 11, 15], target = 9
** 因为 nums[0] + nums[1] = 2 + 7 = 9
** 所以返回 [0, 1]
*/

// [include]
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using std::map;
using std::vector;
// [include]

// [solution]

/*
** 暴力穷举法，使用两个 for 循环即可实现
** 遍历每个元素 x，并查找是否存在一个值与 target - x 相等的目标元素
** 时间复杂度：big O(n**2)
** 空间复杂度：big O(1)
**
** 仔细观察，时间复杂度和空间复杂度权衡
** 时间复杂度的提升是以空间复杂度为代价的
*/
class Solution1
{
public:
    static vector<int> twoSum(vector<int> &nums, int target)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] == target - nums[i])
                {
                    vector<int> iVec;
                    iVec.push_back(i);
                    iVec.push_back(j);
                    return iVec;
                }
                else
                {
                    continue;
                }
            }
        }
        throw("No two sum solution");
    }
};

/*
** 元素和下标，键值对方式储存
** 遍历键值对的键 key，并查找是否存在一个值与 target - key 相等的键值对应的value即为所求下标
** 时间复杂度：big O(n)
** 空间复杂度：big O(1)
**
** 仔细观察，时间复杂度和空间复杂度权衡
** 时间复杂度的提升是以空间复杂度为代价的
*/
class Solution2
{
public:
    static vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> iMap;
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 数组的值作为 map的 key；下标作为 map的 value
            iMap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int temp = target - nums[i];
            // 检索到数组中的值，同时满足同一个元素不能使用两遍
            if (iMap.count(temp) && iMap[temp] != i)
            {
                ret.push_back(i);
                ret.push_back(iMap[temp]);
                break;
            }
        }

        return ret;
    }
};

/*
 * 算法核心思想，组合数据和数据的下标为键值对
 * 哈希映射 hash_map
 * 还是对所有数据进行扫描，然后进行对比处理
 * 利用 C11 standard with unordered_map class 进行处理，本身语言的特性
*/
class Solution3
{
public:
    static vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        // unordered_map for C11 standard
        std::unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 进栈 push
            result.push_back(i);
            //hash_map[nums[i]] = i;
            if (hash_map.find(target - nums[i]) != hash_map.end())
            {
                result.push_back(hash_map[target - nums[i]]);
                hash_map[nums[i]] = i;
                return result;
            }
            hash_map[nums[i]] = i;
            // 出栈 pop
            result.pop_back();
        }
        return result;
    }
};
// [solution]

/*
** Main function
*/
int main(int argc, char **argv)
{
    // [test]
    vector<int> nums{-1, -2, -3, -4, -5};
    int target = -8;

    // vector<int> ivec = Solution1::twoSum(nums, target);
    // vector<int> ivec = Solution2::twoSum(nums, target);
    vector<int> ivec = Solution3::twoSum(nums, target);

    std::cout << "the index of two integer : ";
    for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    // [test]

    return 0;
}
