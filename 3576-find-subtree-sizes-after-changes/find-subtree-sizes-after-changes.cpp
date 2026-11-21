class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> ch(n);
        for (int i = 1; i < n; i++) ch[parent[i]].push_back(i);

        vector<int> np(n, -1), order, last(26, -1), saved(n, -1), idx(n, 0);
        order.reserve(n);

        vector<int> st = {0};
        // enter node 0
        order.push_back(0);
        saved[0] = last[s[0] - 'a'];
        last[s[0] - 'a'] = 0;

        while (!st.empty()) {
            int u = st.back();
            if (idx[u] < (int)ch[u].size()) {
                int v = ch[u][idx[u]++];
                int c = s[v] - 'a';
                np[v] = (last[c] != -1) ? last[c] : parent[v];
                order.push_back(v);
                saved[v] = last[c];
                last[c] = v;
                st.push_back(v);
            } else {
                last[s[u] - 'a'] = saved[u];   // exit: restore
                st.pop_back();
            }
        }

        vector<int> sz(n, 1);
        for (int i = n - 1; i >= 1; i--) {
            int x = order[i];
            sz[np[x]] += sz[x];
        }
        return sz;
    }
};