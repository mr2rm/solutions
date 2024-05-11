from typing import List
from collections import deque


class Solution:
    DIGIT_TO_LETTERS = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def get_combinations(self, current: str) -> List[str]:
        # Recursive - Time: O(4^n), Space: O(n*4^n)
        if len(current) == len(self._digits):
            return [current]
        index = len(current)
        digit = self._digits[index]
        res: List[str] = []
        for letter in self.DIGIT_TO_LETTERS[digit]:
            res.extend(self.get_combinations(current + letter))
        return res

    def get_iterative_combinations(self) -> List[str]:
        # Iterative - Time: O(4^n), Space: O(4^n)
        q = deque()
        q.append("")
        while len(q[0]) < len(self._digits):
            current = q.popleft()
            index = len(current)
            digit = self._digits[index]
            for letter in self.DIGIT_TO_LETTERS[digit]:
                q.append(current + letter)
        return list(q)

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        self._digits = digits
        # return self.get_combinations("")
        return self.get_iterative_combinations()
