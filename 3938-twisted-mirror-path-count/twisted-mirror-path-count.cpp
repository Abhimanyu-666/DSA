class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> R(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> D(m + 1, vector<int>(n + 1, 0));
        R[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int f = (R[i][j] + D[i][j]) % MOD;
                    if (i == m - 1 && j == n - 1) return f;
                    R[i][j + 1] = (R[i][j + 1] + f) % MOD;
                    D[i + 1][j] = (D[i + 1][j] + f) % MOD;
                } else {
                    D[i + 1][j] = (D[i + 1][j] + R[i][j]) % MOD;
                    R[i][j + 1] = (R[i][j + 1] + D[i][j]) % MOD;
                }
            }
        }
        return 0;
    }
};