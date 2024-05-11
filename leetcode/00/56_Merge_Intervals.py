from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Sorting - Time: O(nlogn), Space: O(n)
        sorted_intervals = sorted(intervals)
        res: List[List[int]] = [sorted_intervals[0]]
        for interval in sorted_intervals[1:]:
            if res[-1][0] <= interval[0] <= res[-1][1]:
                res[-1][1] = max(res[-1][1], interval[1])
            else:
                res.append(interval)
        return res
