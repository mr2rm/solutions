class Solution:
    def __init__(self):
        self.s = None
        self.res = None

    def update_longest_palindrome(self, i: int, j: int) -> None:
        n = len(self.s)
        while 0 <= i < n and 0 <= j < n and self.s[i] == self.s[j]:
            i -= 1
            j += 1
        i += 1
        j -= 1
        if j - i + 1 > len(self.res):
            self.res = self.s[i:j + 1]

    def longestPalindrome(self, s: str) -> str:
        # Time: O(n^2), Space: O(n)
        self.s = s
        self.res = ""
        for i in range(len(s)):
            self.update_longest_palindrome(i - 1, i + 1)
            self.update_longest_palindrome(i, i + 1)
        return self.res
