class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        vector<bool> prev(n, false), cur(n, false);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            fill(cur.begin(), cur.end(), false);

            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 1 || prev[j - 1])) {

                    cur[j] = true;

                    if (j - i + 1 >= k) {
                        dp[i] = max(dp[i], 1 + dp[j + 1]);
                    }
                }
            }

            swap(prev, cur);
        }

        return dp[0];
    }
};