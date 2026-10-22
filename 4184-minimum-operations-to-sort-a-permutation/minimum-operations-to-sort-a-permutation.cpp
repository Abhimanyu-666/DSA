class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];

        bool isA = true, isB = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + a) % n) isA = false;
            if (nums[i] != ((a - i) % n + n) % n) isB = false;
        }
        if (!isA && !isB) return -1;

        // state id: type * n + offset, type 0 = A, type 1 = B
        vector<int> dist(2 * n, -1);
        queue<int> q;
        if (isA) { dist[a] = 0; q.push(a); }
        if (isB && dist[n + a] == -1) { dist[n + a] = 0; q.push(n + a); }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int t = cur / n, o = cur % n;
            int nxt[2];
            if (t == 0) {
                nxt[0] = (o + 1) % n;                  // A: rotate -> (A, o+1)
                nxt[1] = n + (o - 1 + n) % n;          // A: reverse -> (B, o-1)
            } else {
                nxt[0] = n + (o - 1 + n) % n;          // B: rotate -> (B, o-1)
                nxt[1] = (o + 1) % n;                  // B: reverse -> (A, o+1)
            }
            for (int v : nxt) {
                if (dist[v] == -1) {
                    dist[v] = dist[cur] + 1;
                    q.push(v);
                }
            }
        }
        return dist[0];
    }
};