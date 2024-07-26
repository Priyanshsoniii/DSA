//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 //color==0 -> black color==1 -> white
    bool bfs(int src,vector<bool>&vis,vector<int>&color,vector<int>&parent,vector<int>graph[]){
        //component started
        bool curColor = true;
        color[src] = curColor;
        curColor = !curColor;
        vis[src] = true;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            for(auto nbr : graph[curNode]){
                if(vis[nbr]==false){
                    vis[nbr] = true;
                    q.push(nbr);
                    parent[nbr] = curNode;
                    color[nbr] = !color[parent[nbr]];
                }
                else{
                    if(parent[nbr]!=-1){
                        if(color[curNode]==color[nbr]) return false;
                    }
                }
            }
        }

        return true;
    }
	bool isBipartite(int V, vector<int>graph[]){
	    // Code here
        vector<int>parent(V,-1);
        vector<int>color(V,-1);
        vector<bool>vis(V,false);

        for(int i=0;i<V;++i){
            // handle multiple component
            if(vis[i]==false){
                if(bfs(i,vis,color,parent,graph)==false) return false;
            }
        }
        // do set mai graph ko break kar skte
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends