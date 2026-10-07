class Solution {
public:
    void dfs(int node, vector<vector<int>>& arr ,vector<int>&vis){
        vis[node]=1 ; //mark the node as one
        int n = arr.size();
        // traverse its neighbours
        for(int i=0 ; i<n ; i++){
            if(arr[node][i]==1 && !vis[i]){
                dfs(i,arr,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> vis(n,0);//visited array with zeroes
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                count++;
                dfs(i,arr,vis);
            }
        }
        return count;
    }
};