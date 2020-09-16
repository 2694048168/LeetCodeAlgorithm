#
# LeetCodeLink: https://leetcode-cn.com/problems/two-sum/
#
# 1. 两数之和
# 给定一个整数数组 nums 和一个目标值 target，
# 请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
# 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
#
# 示例:
# 给定 nums = [2, 7, 11, 15], target = 9
# 因为 nums[0] + nums[1] = 2 + 7 = 9
# 所以返回 [0, 1]
#


class Solution1:
    """
    暴力穷举法，使用两个 for 循环即可实现
    遍历每个元素 x，并查找是否存在一个值与 target - x 相等的目标元素
    时间复杂度：big O(n**2)
    空间复杂度：big O(1)

    仔细观察，时间复杂度和空间复杂度权衡
    时间复杂度的提升是以空间复杂度为代价的
    """

    def twoSum(self, nums, target):
        index = []
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]
    

class Solution2:
    """
    元素和下标，键值对方式储存,字典数据结构
    遍历键值对的键 key，并查找是否存在一个值与 target - key 相等的键值对应的value即为所求下标
    时间复杂度：big O(n)
    空间复杂度：big O(1)

    仔细观察，时间复杂度和空间复杂度权衡
    时间复杂度的提升是以空间复杂度为代价的
    """

    def twoSum(self, nums, target):
        map_dict = dict()
        ret = list()
        for item in range(len(nums)):
            map_dict[nums[item]] = item
        
        for i in range(len(nums)):
            temp = target - nums[i]
            if temp in map_dict.keys() and map_dict[temp] != i:
                ret.append(i)
                ret.append(map_dict[temp])
                break;

        return ret


class Solution3:
    """
    enumerate 遍历 list，
    将一个可遍历的数据对象(如列表、元组或字符串)
    组合为一个索引序列，同时列出数据和数据下标，一般用在 for 循环当中 
    
    组合数据和数据下标思想！！！
    算法核心思想与 solution2 一致，只不过使用Python 内置函数 enumerate 实现
    """
    def twoSum(self, nums, target):
        dict = {}
        # enumerate 内置函数，常用 for 循环遍历一个容器/迭代器
        # 参数 sequence -- 一个序列、迭代器或其他支持迭代对象
        # 参数 start -- 下标起始位置
        # 返回值 返回 enumerate(枚举) 对象
        for i,n in enumerate(nums,0):
            if target - n in dict:
                return [dict[target-n],i]
            dict[n] = i
                


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    # solution = Solution1()
    # solution = Solution2()
    solution = Solution3()
    print(solution.twoSum(nums, target))

    