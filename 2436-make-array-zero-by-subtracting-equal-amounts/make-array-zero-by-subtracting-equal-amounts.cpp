class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,bool>vis;
        for(auto x : nums){
            if(x!=0 && vis[x]==false){
                cnt++;
                vis[x] = true; 
            }
        }
        return cnt;
    }
};