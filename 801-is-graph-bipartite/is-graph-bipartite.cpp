class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue;   // already handled this component

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int it : graph[node]) {
                    if (color[it] == -1) {
                        color[it] = !color[node];
                        q.push(it);          // enqueue the neighbor
                    } 
                    else if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};