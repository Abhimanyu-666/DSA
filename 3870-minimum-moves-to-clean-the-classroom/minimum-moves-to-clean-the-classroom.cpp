class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> litterPos;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') litterPos.push_back({i, j});
            }

        int k = litterPos.size();
        int fullMask = (1 << k) - 1;
        if (k == 0) return 0;

        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        for (int idx = 0; idx < k; idx++)
            litterIdx[litterPos[idx].first][litterPos[idx].second] = idx;

        int maskCnt = 1 << k;
        int E = energy + 1;
        long long total = (long long)m * n * maskCnt * E;
        vector<uint8_t> visited(total, 0); // byte array — faster than vector<bool>'s bit-fiddling

        auto encode = [&](int r, int c, int mask, int e) -> int {
            return ((r * n + c) * maskCnt + mask) * E + e;
        };

        static const int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};

        vector<int> curLevel, nextLevel;
        int startEnc = encode(sr, sc, 0, energy);
        visited[startEnc] = 1;
        curLevel.push_back(startEnc);

        int steps = 0;
        while (!curLevel.empty()) {
            nextLevel.clear();
            for (int enc : curLevel) {
                int e = enc % E;
                int tmp = enc / E;
                int mask = tmp % maskCnt;
                int pos = tmp / maskCnt;
                int c = pos % n;
                int r = pos / n;

                if (mask == fullMask) return steps;
                if (e == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    char ch = classroom[nr][nc];
                    if (ch == 'X') continue;

                    int ne = e - 1;
                    int nmask = mask;
                    if (litterIdx[nr][nc] != -1) nmask |= (1 << litterIdx[nr][nc]);
                    if (ch == 'R') ne = energy;

                    int nenc = encode(nr, nc, nmask, ne);
                    if (!visited[nenc]) {
                        visited[nenc] = 1;
                        nextLevel.push_back(nenc);
                    }
                }
            }
            steps++;
            swap(curLevel, nextLevel);
        }

        return -1;
    }
};