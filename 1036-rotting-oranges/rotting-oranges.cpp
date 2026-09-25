class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q; // just {row, col} — no need to store time per node
        int cntFresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) cntFresh++;
            }
        }

        if (cntFresh == 0) return 0; // no fresh oranges to begin with

        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // level-by-level BFS: each full round = 1 minute
        while (!q.empty() && cntFresh > 0) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = r + delrow[i];
                    int ncol = c + delcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        cntFresh--;
                        q.push({nrow, ncol});
                    }
                }
            }
            time++;
        }

        return cntFresh == 0 ? time : -1;
    }
};