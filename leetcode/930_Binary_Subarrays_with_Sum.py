from typing import List

class Solution:
    def solution_1(self, nums: List[int], goal: int) -> int:
        # Prefix Sum, Hash Table - Time: O(n), Space: O(n)  
        res = 0
        current_sum = 0
        freq = {0: 1}
        for x in nums:
            current_sum += x
            res += freq.get(current_sum - goal, 0)
            freq.setdefault(current_sum, 0)
            freq[current_sum] += 1

        return res    
        
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.solution_1(nums, goal)