class Solution {
public:
    void dfs(int i,vector<vector<int>>&rooms,vector<bool>&vis){
        vis[i] = true;
        for(auto it : rooms[i]){
            if(vis[it]==false)
            dfs(it,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool>vis(n,false);
        
        dfs(0,rooms,vis);

        for(auto it : vis){
            if(it==false) return false;
        }
        return true;
    }
};