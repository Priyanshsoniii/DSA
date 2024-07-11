class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int center = -1;
        int maxEle = -1;
        int maxFreq = -1;
        unordered_map<int,int>mp;
        for(auto x : edges){
            int a = x[0];
            int b = x[1];
            mp[a]++;
            mp[b]++;
            if(mp[a]>maxFreq){
                maxFreq = mp[a];
                maxEle = a;
            }
            if(mp[b]>maxFreq){
                maxFreq = mp[b];
                maxEle = b;
            }
        }
        return maxEle;
    }
};