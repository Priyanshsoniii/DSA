class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center = -1;
        int maxEle = -1;
        int maxFreq = -1;
        unordered_map<int,int>mp;
        for(auto x : edges){
            for(auto y : x){
                mp[y]++;
                if(mp[y]>maxFreq){
                    maxFreq = mp[y];
                    maxEle = y;
                }
            }
        }
        return maxEle;
    }
};