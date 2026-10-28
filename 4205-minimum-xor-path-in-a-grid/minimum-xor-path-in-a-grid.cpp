class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int V = 1024;

        // dp[j] = reachable XOR values for the current row at column j
        vector<bitset<V>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<V> from;
                if (i == 0 && j == 0) {
                    from[0] = 1;                 // XOR of nothing is 0
                } else {
                    if (i > 0) from |= dp[j];     // from above (old dp[j])
                    if (j > 0) from |= dp[j - 1]; // from left (already updated)
                }

                bitset<V> cur;
                for (int x = 0; x < V; x++)
                    if (from[x]) cur[x ^ grid[i][j]] = 1;

                dp[j] = cur;
            }
        }

        for (int x = 0; x < V; x++)
            if (dp[n - 1][x]) return x;
        return 0;
    }
};