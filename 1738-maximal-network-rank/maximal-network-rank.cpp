class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>>connected(n,vector<bool>(n,false));
        unordered_map<int,int>deg;
        for(auto i : roads){
            deg[i[0]]++;
            deg[i[1]]++;
            connected[i[0]][i[1]]=true;
            connected[i[1]][i[0]]=true;
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(connected[i][j]==false)
                maxi = max(maxi,deg[i]+deg[j]);
                else
                maxi = max(maxi,deg[i]+deg[j]-1);
            }
        }
        return maxi;
    }
};