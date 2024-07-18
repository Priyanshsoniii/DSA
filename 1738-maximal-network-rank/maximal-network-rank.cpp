class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,int>freq;
        vector<vector<int>>gr(n+1,vector<int>(n+1,-1));
        for(auto it : gr){
            for(auto itt : it){
                cout<<itt<<" ";
            }cout<<endl;
        }
        for(auto road: roads){
            freq[road[0]]++;
            freq[road[1]]++;
            cout<<road[0]<<" "<<road[1]<<endl;
            gr[road[0]][road[1]] = 1;
            gr[road[1]][road[0]] = 1;
        }

        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;i!=j && j<n;++j){
               if(gr[i][j]==1 && gr[j][i]==1)
                ans = max(ans,freq[i]+freq[j]-1);
                else 
                ans = max(ans,freq[i]+freq[j]);
            }
        }

        return ans;
    }
};