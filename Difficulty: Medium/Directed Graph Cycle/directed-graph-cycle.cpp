//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void dfs(int src, vector<int>adj[], vector<bool>&vis,vector<bool>&pathVis,bool &cycle){
        vis[src] = true;
        pathVis[src] = true;
        for(auto nbr : adj[src]){
            if(pathVis[nbr]==true){
                cycle = true;
                return;
            }
            if(vis[nbr]==false){
                dfs(nbr,adj,vis,pathVis,cycle);
            }
        }
        pathVis[src]=false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false);
        vector<bool>pathVis(V,false);
        
        bool cycle = false;
        
        for(int i=0;i<V;++i){
            if(vis[i]==false){
                dfs(i,adj,vis,pathVis,cycle);
                if(cycle==true) return true;
            }
            else if(cycle) return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends