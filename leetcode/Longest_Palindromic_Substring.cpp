#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // Longest Common Substring - Time: O(n^2), Space: O(n^2)
        int n = s.length();
        int l = 0, r = 0;
        int dp[1010][1010] = {0};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (s[i] == s[n - j - 1])
                {
                    dp[i][j] = (i && j ? dp[i - 1][j - 1] : 0) + 1;
                    int k = i - dp[i][j] + 1;
                    if (j == n - k - 1 && dp[i][j] > r - l + 1)
                        l = k, r = i;
                }
        return string(s.begin() + l, s.begin() + r + 1);
    }
};

int main()
{
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}