class Solution {
    int n, LOG, timer = 0;
    vector<int> tin, tout, depth, base, bit, mask;
    vector<vector<int>> up;

    void add(int i, int v) { for (i++; i <= n + 1; i += i & -i) bit[i] ^= v; }
    int query(int i) { int r = 0; for (i++; i > 0; i -= i & -i) r ^= bit[i]; return r; }
    int P(int x) { return base[x] ^ query(tin[x]); }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++) if (diff >> k & 1) a = up[k][a];
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--)
            if (up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
        return up[0][a];
    }

public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_;
        LOG = 1;
        while ((1 << LOG) < n) LOG++;

        vector<vector<int>> adj(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }

        tin.assign(n, 0); tout.assign(n, 0); depth.assign(n, 0);
        base.assign(n, 0); mask.assign(n, 0); bit.assign(n + 2, 0);
        up.assign(LOG, vector<int>(n, 0));
        for (int i = 0; i < n; i++) mask[i] = 1 << (s[i] - 'a');

        // iterative DFS from root 0
        vector<int> st = {0}, idx(n, 0);
        up[0][0] = 0;
        base[0] = mask[0];
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (idx[u] < (int)adj[u].size()) {
                int v = adj[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ mask[v];
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        vector<bool> ans;
        for (auto& q : queries) {
            istringstream ss(q);
            string type, a, b;
            ss >> type >> a >> b;
            if (type == "update") {
                int u = stoi(a);
                int c = b[0] - 'a';
                int nm = 1 << c;
                if (nm != mask[u]) {
                    int delta = mask[u] ^ nm;
                    add(tin[u], delta);
                    add(tout[u] + 1, delta);
                    mask[u] = nm;
                }
            } else {
                int u = stoi(a), v = stoi(b);
                int l = lca(u, v);
                int m = P(u) ^ P(v) ^ mask[l];
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};