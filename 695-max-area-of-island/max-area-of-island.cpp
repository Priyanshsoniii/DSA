class Solution {
public:
    int dirx[4] = {-1,0,1,0};
    int diry[4] = {0,-1,0,1};
    void dfs(int i,int j,vector<vector<bool>>&vis,int &value,vector<vector<int>>&grid,int m,int n){
        vis[i][j]=true;
        for(int k=0;k<4;++k){
            int nrow = i + dirx[k];
            int ncol = j + diry[k];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==false && grid[nrow][ncol]==1){
                value+=1;
                dfs(nrow,ncol,vis,value,grid,m,n);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>vis(row+1,vector<bool>(col+1,false));
        int ans = 0;

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(vis[i][j]==false && grid[i][j]){
                    int val = 1;
                    dfs(i,j,vis,val,grid,row,col);
                    ans = max(ans,val);
                }
                vis[i][j]=true;
            }
        }
        return ans;
    }
};