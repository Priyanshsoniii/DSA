//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
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
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
        //code here
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

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends