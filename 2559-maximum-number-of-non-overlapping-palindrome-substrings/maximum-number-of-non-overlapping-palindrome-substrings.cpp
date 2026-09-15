class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[l][r] = whether s[l..r] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                if (len == 1) {
                    pal[l][r] = true;
                }
                else if (len == 2) {
                    pal[l][r] = (s[l] == s[r]);
                }
                else {
                    pal[l][r] = (s[l] == s[r] && pal[l + 1][r - 1]);
                }
            }
        }

        // dp[i] = max number of palindromes in s[0..i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            // Don't use s[i]
            dp[i + 1] = dp[i];

            // Try every palindrome ending at i
            for (int j = 0; j <= i; j++) {
                int len = i - j + 1;

                if (len >= k && pal[j][i]) {
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};