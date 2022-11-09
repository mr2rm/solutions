from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Prefix/Suffix Multiplication - Time: O(n), Space: O(n)
        premul = [1]
        for x in nums:
            premul.append(premul[-1] * x)

        postmul = [1] * (len(nums) + 1)
        for i in reversed(range(len(nums))):
            postmul[i] = postmul[i + 1] * nums[i]

        res = []
        for i in range(len(nums)):
            res.append(premul[i] * postmul[i + 1])
        return res
