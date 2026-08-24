class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        if (n == 1) return 0;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        // dp[n] = 0 (base case, game over)
        long long g_n = prefix[n] - 0;

        long long sufMax      = g_n;  // running max(g[j]) for j in [i+1, n]
        long long sufMaxFrom2 = g_n;  // running max(g[j]) for j in [2, n]  -> used only for dp[0]

        for (int i = n - 1; i >= 1; i--) {
            long long dp_i = sufMax;              // lo(i) = i+1 for all i >= 1
            long long g_i  = prefix[i] - dp_i;

            sufMax = max(sufMax, g_i);             // now covers [i, n]
            if (i >= 2) sufMaxFrom2 = max(sufMaxFrom2, g_i);  // exclude g[1]
        }

        // dp[0]: lo(0) = 2, so it needs max(g[2..n]), never g[1]
        return sufMaxFrom2;
    }
};