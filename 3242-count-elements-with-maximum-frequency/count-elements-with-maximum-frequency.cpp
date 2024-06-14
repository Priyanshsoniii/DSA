class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxF = 0;
        for(auto x : nums){
            mp[x]++;
            maxF = max(maxF,mp[x]);
        }
        maxF;
        int cnt =0;
        for(auto x : nums){
            if(mp[x]==maxF) cnt++;
        }
        return cnt;
    }
};