class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int cnt = 0;

        static const int drow[] = {-1, 1, 0, 0};
        static const int dcol[] = {0, 0, -1, 1};

        vector<int> stack; // encode row*m + col
        stack.reserve(n * m);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] != '1') continue;
                cnt++;

                // iterative DFS using grid itself as visited marker
                grid[row][col] = '0';
                stack.push_back(row * m + col);

                while (!stack.empty()) {
                    int code = stack.back();
                    stack.pop_back();
                    int r = code / m;
                    int c = code % m;

                    for (int i = 0; i < 4; i++) {
                        int nr = r + drow[i];
                        int nc = c + dcol[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                            grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            stack.push_back(nr * m + nc);
                        }
                    }
                }
            }
        }
        return cnt;
    }
};