class Solution:
    def solution_1(self, n: int) -> int:
        # Brute Force - Time: O(n), Space: O(1)
        s = n * (n + 1) // 2
        x = 0
        for i in range(1, n + 1):
            if x + i == s - x: 
                return i
            x += i
        return -1

    def pivotInteger(self, n: int) -> int:
        return self.solution_1(n)
