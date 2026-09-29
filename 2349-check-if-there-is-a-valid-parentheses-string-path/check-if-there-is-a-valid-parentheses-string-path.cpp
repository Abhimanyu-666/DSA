class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int pathLen = m + n - 1;

        // A valid parentheses string must have even length
        if (pathLen % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        // dp[i][j]: bitset of possible balances reachable at (i,j)
        vector<vector<bitset<205>>> dp(m, vector<bitset<205>>(n));

        dp[0][0][1] = 1; // grid[0][0] must be '(' (checked above), balance = 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                bitset<205> combined;
                if (i > 0) combined |= dp[i-1][j];
                if (j > 0) combined |= dp[i][j-1];

                if (combined.none()) continue; // unreachable

                bitset<205> next;
                if (grid[i][j] == '(') {
                    // shift all balances up by 1 (balance + 1)
                    next = combined << 1;
                } else {
                    // shift all balances down by 1 (balance - 1), drop negatives
                    next = combined >> 1;
                }
                dp[i][j] = next;
            }
        }

        return dp[m-1][n-1][0]; // balance 0 reachable at destination
    }
};