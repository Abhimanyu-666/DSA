class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                // first row , last row , first column , last column
                if(i==0 || j==0 || i==(n-1) || j==(m-1)){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,1,-1};
        //BFS
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0 ; i<4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                   }

            }
        }
        int count=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        
        return count;
    }
};