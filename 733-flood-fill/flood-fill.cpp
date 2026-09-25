class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& ans, int row, int col, int color ,int iniColor,int delRow[], int delCol[]){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
               image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){//  image[nrow][ncol]==iniColor means if they are connected with the same color and ans[nrow][ncol]!=color means if it had not been visited earlier
               ans[nrow][ncol] = color;
               dfs(image,ans,nrow,ncol,color,iniColor,delRow,delCol) ;
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc]; // initial color
        vector<vector<int>> ans = image; // copy image

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(image,ans,sr,sc,color,iniColor,delRow,delCol);

        return ans;
    }
};