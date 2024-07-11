class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int maxEle = -1;
        int maxFreq = -1,a,b;
        unordered_map<int,int>mp;
        for(auto x : edges){
            a = x[0];
            b = x[1];
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