class Solution:
    def expand_around_center(self, s: str, i: int, j: int) -> int:
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
        return j - i - 1

    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        # Time: O(n^2), Space: O(1)
        cnt = l = r = 0
        for i in range(n):
            c = max(self.expand_around_center(s, i, i),
                    self.expand_around_center(s, i, i + 1))
            if c > cnt:
                cnt = c
                l = i - ((c - 1) // 2)
                r = i + (c // 2)
        return s[l:r + 1]

        # Longest Common Substring (TLE in Python) - Time: O(n^2), Space: O(n^2)
        # l = r = 0
        # lcsubstr = [[0] * n for _ in range(n)]
        # for i in range(n):
        #     for j in range(n):
        #         if s[i] == s[n - j - 1]:
        #             c = (lcsubstr[i - 1][j - 1] if i and j else 0) + 1
        #             k = i - c + 1
        #             if j == n - k - 1 and c > r - l + 1:
        #                 l, r = k, i
        #             lcsubstr[i][j] = c
        # return s[l:r + 1]

        # DP - Time: O(n^2), Space: O(n^2)
        # dp = [[False] * n for _ in range(n)]
        # for i in reversed(range(n)):
        #     dp[i][i] = True
        #     if i + 1 < n:
        #         dp[i][i + 1] = (s[i] == s[i + 1])
        #     for j in range(i + 2, n):
        #         if s[i] == s[j]:
        #             dp[i][j] = dp[i + 1][j - 1]
        # for c in reversed(range(n)):
        #     for i in range(n - c):
        #         if dp[i][i + c]:
        #             return s[i:i + c + 1]


print(Solution().longestPalindrome(input()))
