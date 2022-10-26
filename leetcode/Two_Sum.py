from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Brute Force - Time: O(n^2), Space: O(1)
        # for i, x in enumerate(nums):
        #     for j, y in enumerate(nums[i + 1:], start=i + 1):
        #         if x + y == target:
        #             return [i, j]

        # Hash Table - Time: O(n), Space: O(n)
        # index = {}
        # for i, x in enumerate(nums):
        #     index[x] = i
        # for i, a in enumerate(nums):
        #     b = target - a
        #     if b in index and index[b] != i:
        #         return [i, index[b]]

        # Hash Table - Time: O(n), Space: O(n)
        index = {}
        for i, a in enumerate(nums):
            b = target - a
            if b in index:
                return [i, index[b]]
            index[a] = i
