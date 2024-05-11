from typing import List

class Solution(object):
    def solution_1(self, points: List[List[int]]) -> int:
        # Greedy - Time: O(nlogn), Space: O(1)
        points.sort()
        interval = points[0]
        count = 1
        for point in points:
            if point[0] <= interval[1]:
                interval = [point[0], min(interval[1], point[1])]
            else:
                interval = point
                count += 1
        return count

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        return self.solution_1(points)
