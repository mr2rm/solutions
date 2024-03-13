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
    
    def solution_2(self, n: int) -> int:
        # Two Pointers - Time: O(n), Space: O(1)
        l, r = 1, n 
        sum_l, sum_r = 1, n     
        while l < r:
            if sum_l < sum_r:
                l += 1
                sum_l += l
            else:
                r -= 1
                sum_r += r

        if l == r and sum_l == sum_r:
            return l
        return -1 

    def pivotInteger(self, n: int) -> int:
        return self.solution_2(n)
