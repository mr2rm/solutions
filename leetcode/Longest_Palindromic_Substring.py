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
        # self.s = s
        # self.res = ""
        # for i in range(len(s)):
        #     self.update_longest_palindrome(i - 1, i + 1)
        #     self.update_longest_palindrome(i, i + 1)
        # return self.res

        # Longest Common Substring (TLE in Python) - Time: O(n^2), Space: O(n^2)
        n = len(s)
        l = r = 0
        lcsubstr = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if s[i] == s[n - j - 1]:
                    c = (lcsubstr[i - 1][j - 1] if i and j else 0) + 1
                    k = i - c + 1
                    if j == n - k - 1 and c > r - l + 1:
                        l, r = k, i
                    lcsubstr[i][j] = c
        return s[l:r + 1]


print(Solution().longestPalindrome(input()))
