class Solution {
public:
    //color==0 -> black color==1 -> white
    bool bfs(int src,vector<bool>&vis,vector<int>&color,vector<int>&parent,vector<vector<int>>&graph){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
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