class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>vis;
        for(auto it : nums1){
            vis[it]++;
        }
        vector<int>res;
        for(auto it : nums2){
            if(vis[it]>=1){
                res.push_back(it);
                vis[it]--;
            }
        }
        return res;
    }
};