class Solution {
public:
    int minDifference(vector<int>& nums) {
        int len = nums.size();
        if(len<=4) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        
        for(int left=0,right=len-4;left<=3;++left,right++){
           mini = min(mini,nums[right]-nums[left]);
        }
        return mini;
    }
};