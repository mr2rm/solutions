import heapq
from typing import List
from collections import deque
from bisect import insort_left, bisect_left


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        # 2 Pointers & Binary search - Time: O(nlogn), Space: O(n)
        # i, sorted_nums = 0, []
        # for j, x in enumerate(nums):
        #     insort_left(sorted_nums, x)
        #     if sorted_nums[-1] - sorted_nums[0] > limit:
        #         sorted_nums.pop(bisect_left(sorted_nums, nums[i]))
        #         i += 1
        # return j - i + 1

        # 2 Pointers & Heap - Time: O(nlogn), Space: O(n)
        # minq, maxq = [], []
        # i, res = 0, 0
        # for j, x in enumerate(nums):
        #     heapq.heappush(minq, (x, j))
        #     heapq.heappush(maxq, (-x, j))
        #     if -maxq[0][0] - minq[0][0] > limit:
        #         i = min(minq[0][1], maxq[0][1]) + 1
        #         while minq[0][1] < i:
        #             heapq.heappop(minq)
        #         while maxq[0][1] < i:
        #             heapq.heappop(maxq)
        #     res = max(res, j - i + 1)
        # return res

        # 2 Pointers & Sliding Window Max/Min - Time: O(n), Space: O(n)
        mini, maxi = deque(), deque()
        i = 0
        for j, x in enumerate(nums):
            while mini and mini[-1] > x:
                mini.pop()
            mini.append(x)
            while maxi and maxi[-1] < x:
                maxi.pop()
            maxi.append(x)
            if maxi[0] - mini[0] > limit:
                if mini[0] == nums[i]:
                    mini.popleft()
                if maxi[0] == nums[i]:
                    maxi.popleft()
                i += 1
        return len(nums) - i
