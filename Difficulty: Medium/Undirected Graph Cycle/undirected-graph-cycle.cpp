//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(int src,vector<int>adj[],vector<bool>&vis,int parent,bool &cycle){
        vis[src]=true;
        for(auto it : adj[src]){
            if(vis[it]==false){
                
                dfs(it,adj,vis,src,cycle);
                vis[it] = true;
            }
            else{
                if(it!=parent){
                    cycle = true;
                    return;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,false);
        bool cycle = false;
        for(int i=0;i<V;++i){
            if(vis[i]==false){
                dfs(i,adj,vis,-1,cycle);
            }
            if(cycle==true) break;
        }
        return cycle;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends