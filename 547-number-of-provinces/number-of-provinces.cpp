class Solution {
public:
    void dfs(int node, vector<vector<int>>& arr, vector<int>& vis) {
        // adjacency matrix method
        vis[node] = 1;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[node][j] == 1 && !vis[j]) {
                dfs(j, arr, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, arr, vis);
            }
        }
        return count;
    }
};