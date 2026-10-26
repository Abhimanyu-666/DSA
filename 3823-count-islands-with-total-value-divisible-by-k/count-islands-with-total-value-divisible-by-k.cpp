class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int count = 0;

        vector<pair<int, int>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                long long total = 0;
                total += grid[i][j];
                grid[i][j] = 0;
                st.push_back({i, j});

                while (!st.empty()) {
                    auto [r, c] = st.back();
                    st.pop_back();
                    for (int d = 0; d < 4; d++) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                            total += grid[nr][nc];
                            grid[nr][nc] = 0;
                            st.push_back({nr, nc});
                        }
                    }
                }

                if (total % k == 0) count++;
            }
        }
        return count;
    }
};