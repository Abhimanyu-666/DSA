class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int land = 0;
        for (auto& row : grid)
            for (int x : row) land += x;

        vector<pair<int, int>> st;
        auto push = [&](int r, int c) {
            if (grid[r][c] == 1) {
                grid[r][c] = 0;   // sink it (visited)
                land--;           // it can escape, so not an enclave
                st.push_back({r, c});
            }
        };

        // seed only from border land cells (O(n + m), not O(n*m))
        for (int i = 0; i < n; i++) { push(i, 0); push(i, m - 1); }
        for (int j = 0; j < m; j++) { push(0, j); push(n - 1, j); }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!st.empty()) {
            auto [r, c] = st.back();
            st.pop_back();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                    push(nr, nc);
            }
        }

        return land;
    }
};