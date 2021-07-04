/**
 * @File    : twoSum.cpp
 * @Brief   : 两数之和
 * @Link    : https://leetcode-cn.com/problems/two-sum/
 * @Author  : Wei Li
 * @Date    : 2021-07-04
*/

// -----------------------------------------------------------------------
// 1、指针与常量
// int x;
// int * p1 = &x; // 指针可以被修改， 值也可以被修改
// const int * p2 = &x; // 指针可以被修改， 值不可以被修改（const int）
// int * const p3 = &x; // 指针不可以被修改（* const）， 值可以被修改
// const int * const p4 = &x; // 指针不可以被修改， 值也不可以被修改

// 2、指针函数与函数指针
// addition是指针函数， 一个返回类型是指针的函数
// int* addition(int a, int b) 
// {
//     int* sum = new int(a + b);
//     return sum;
// }

// int subtraction(int a, int b) 
// {
//     return a - b;
// }

// int operation(int x, int y, int (*func)(int, int)) 
// {
//     return (*func)(x,y);
// }

// // minus是函数指针， 指向函数的指针
// int (*minus)(int, int) = subtraction;
// int* m = addition(1, 2);
// int n = operation(3, *m, minus);
// -----------------------------------------------------------------------


// [include]
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


// -----------------------------
class Solution1
{
public:
    static std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        /*
        ** 暴力穷举法，使用两个 for 循环即可实现
        ** 遍历每个元素 x，并查找是否存在一个值与 target - x 相等的目标元素
        ** 时间复杂度：big O(n**2)
        ** 空间复杂度：big O(1)
        **
        ** 仔细观察，时间复杂度和空间复杂度权衡
        ** 时间复杂度的提升是以空间复杂度为代价的
        */

        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] == target - nums[i])
                {
                    std::vector<int> iVec;
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


// -----------------------------------------
class Solution2
{
public:
    static std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        /*
        ** 元素和下标，键值对方式储存
        ** 遍历键值对的键 key，并查找是否存在一个值与 target - key 相等的键值对应的value即为所求下标
        ** 时间复杂度：big O(n)
        ** 空间复杂度：big O(1)
        **
        ** 仔细观察，时间复杂度和空间复杂度权衡
        ** 时间复杂度的提升是以空间复杂度为代价的
        */

        std::map<int, int> iMap;
        std::vector<int> ret;
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


// -----------------------------------
class Solution3
{
public:
    static std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        /*
        * 算法核心思想，组合数据和数据的下标为键值对
        * 哈希映射 hash_map
        * 还是对所有数据进行扫描，然后进行对比处理
        * 利用 C11 standard with unordered_map class 进行处理，本身语言的特性
        */

        std::vector<int> result;
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


// -----------------------------------
int main(int argc, char **argv)
{
    // [test]
    std::vector<int> nums{-1, -2, -3, -4, -5};
    int target = -8;

    // vector<int> ivec = Solution1::twoSum(nums, target);
    // vector<int> ivec = Solution2::twoSum(nums, target);
    std::vector<int> ivec = Solution3::twoSum(nums, target);

    std::cout << "the index of two integer : ";
    for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
    {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    // [test]

    return 0;
}
