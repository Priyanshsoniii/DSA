class Solution {
public:
    int dirx[4] = {0,-1,0,1};
    int diry[4] = {1,0,-1,0};
    void dfs(int i,int j, vector<vector<char>>&grid,vector<vector<bool>>&vis,int row,int col,bool &isCycle,int pi,int pj){
        vis[i][j]=true;
        for(int k = 0; k<4; ++k){
            int nrow = i + dirx[k];
            int ncol = j + diry[k];
            if(nrow>=0 && ncol>=0 && nrow<row && ncol<col && grid[nrow][ncol]==grid[i][j]){         
                if(vis[nrow][ncol]==false)
                dfs(nrow,ncol,grid,vis,row,col,isCycle,i,j);
                else{
                    if(nrow!=pi && ncol!=pj){
                        isCycle = true;
                        return; 
                    }
                }
            }
        }
    } 
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        bool isCycle = false;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(vis[i][j]==false){
                    dfs(i,j,grid,vis,row,col,isCycle,-1,-1);
                    if(isCycle==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};