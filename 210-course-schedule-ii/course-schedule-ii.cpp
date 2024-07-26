class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<bool>&vis,vector<bool>&pathVis,bool &isCycle,vector<int>&ans){
        vis[src] = true;
        pathVis[src] = true;
        
        for(auto nbr : adj[src]){
            if(vis[nbr]==false){
                dfs(nbr,adj,vis,pathVis,isCycle,ans);
            }
            else if(pathVis[nbr]==true){
                isCycle = true;
                return;
            }
        }
        ans.push_back(src);
        pathVis[src] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>pathVis(numCourses,false);
        bool isCycle = false;
        for(int i=0;i<numCourses;++i){
            if(vis[i]==false){
                dfs(i,adj,vis,pathVis,isCycle,ans);
                if(isCycle) return {}; 
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};