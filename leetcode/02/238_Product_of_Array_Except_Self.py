from typing import List


class Solution:
    def solution_1(self, nums: List[int]) -> List[int]:
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

    def solution_2(self, nums: List[int]) -> List[int]:
        # Prefix/Suffix Multiplication - Time: O(n), Space: O(n)
        n = len(nums)

        prefix = [0] * n
        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] * nums[i]

        suffix = [0] * n
        suffix[n - 1] = nums[n - 1]
        for i in reversed(range(n - 1)):
            suffix[i] = suffix[i + 1] * nums[i]

        ans = [1] * n
        for i in range(n):
            if i - 1 >= 0:
                ans[i] *= prefix[i - 1]
            if i + 1 < n:
                ans[i] *= suffix[i + 1]

        return ans

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        return self.solution_2(nums)
