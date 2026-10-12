class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<int> &check,vector<vector<int>>& graph){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,check,graph)) {
                    check[node]=0;
                    return true;
                }
            }
            else if(vis[it] && pathvis[it]){
                check[node] = 0;
                return true;
            } 
        }

        check[node]=1; // safe node
        pathvis[node] =0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        vector<int> safeNode;

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,check,graph);
            }
        }

        for(int i=0 ; i<n ; i++){
            if(check[i]==1) safeNode.push_back(i);
        }

        return safeNode;
    }
};