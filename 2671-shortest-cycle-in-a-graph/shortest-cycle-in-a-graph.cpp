class Solution {
public:
    void bfs(int src,vector<int>adj[],int &ans,int n){
        queue<int>q;
        q.push(src);
        vector<bool>vis(n,false);
        unordered_map<int,int>parent;
        vector<int>dist(n,-1);
        dist[src]=0;
        parent[src] = -1;
        vis[src]=true;
        int mini = INT_MAX;
        while(!q.empty()){
            int curNode = q.front();
            q.pop();
            for(auto nbr : adj[curNode]){
                if(vis[nbr]==false){
                    if(dist[nbr]==-1){
                        dist[nbr] = dist[curNode]+1;
                    }
                    //insert into queue
                    parent[nbr] = curNode;
                    vis[nbr] = true;
                    q.push(nbr);
                }
                else{
                    if(parent[curNode]!=nbr && parent[nbr] != curNode){
                        mini = min(mini,dist[curNode] + dist[nbr] + 1);
                    }
                    else{
                        //do nothing
                    }
                }
            }
        }
        ans = min(ans,mini);
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int mini = INT_MAX;
        for(int i=0;i<n;++i){
            bfs(i,adj,mini,n);
        }
        return mini==INT_MAX?-1:mini;
    }
};