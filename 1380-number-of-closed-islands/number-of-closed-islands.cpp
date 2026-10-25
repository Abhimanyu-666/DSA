class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // sink every island that touches the border
        for (int i = 0; i < n; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(grid, 0, j);
            dfs(grid, n - 1, j);
        }

        // each remaining island is closed
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != 0)
            return;
        g[i][j] = 1;
        dfs(g, i + 1, j);
        dfs(g, i - 1, j);
        dfs(g, i, j + 1);
        dfs(g, i, j - 1);
    }
};