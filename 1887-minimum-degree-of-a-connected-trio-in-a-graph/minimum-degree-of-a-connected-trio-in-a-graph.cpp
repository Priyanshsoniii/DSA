class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> deg(n+1,0);
        vector<vector<bool>>graph(n+1,vector<bool>(n+1,false));
        int ans= 1e9;
        int m = edges.size();
        for(int i=0;i<m; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            deg[x]++;
            deg[y]++;
            graph[x][y]= true;
            graph[y][x]= true;

        }

        for(int i=1; i<=n; ++i){
            for(int j=i+1; j<=n; ++j){
                if(!graph[i][j]) continue;
                for(int k=j+1; k<=n; ++k){
                    if(graph[i][k] && graph[j][k]){
                        ans = min(ans,deg[i] + deg[j] + deg[k]-6);
                    }
                }
            }
        }

        return ans==1e9?-1:ans;
    }
};