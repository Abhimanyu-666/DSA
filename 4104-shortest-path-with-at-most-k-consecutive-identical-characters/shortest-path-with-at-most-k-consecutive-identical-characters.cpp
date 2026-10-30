class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const int INF = INT_MAX;
        // state id = node * k + (run - 1)
        vector<int> dist((size_t)n * k, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[0] = 0;               // node 0, run 1
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, id] = pq.top();
            pq.pop();
            if (d > dist[id]) continue;

            int u = id / k, run = id % k + 1;
            if (u == n - 1) return d;   // first pop of the target is optimal

            for (auto [v, w] : adj[u]) {
                int nr = (labels[v] == labels[u]) ? run + 1 : 1;
                if (nr > k) continue;
                int nid = v * k + (nr - 1);
                if (d + w < dist[nid]) {
                    dist[nid] = d + w;
                    pq.push({dist[nid], nid});
                }
            }
        }
        return -1;
    }
};