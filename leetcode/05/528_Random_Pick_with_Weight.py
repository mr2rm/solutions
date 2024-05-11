from typing import List
from random import randint
from bisect import bisect_left


class Solution:

    def __init__(self, w: List[int]):
        # Prefix Sum - Time: O(n), Space: O(n)
        self.psum = [w[0]]
        for x in w[1:]:
            self.psum.append(self.psum[-1] + x)

    def pickIndex(self) -> int:
        # Binary Search - Time: O(logn), Space: O(1)
        x = randint(1, self.psum[-1])
        return bisect_left(self.psum, x)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
