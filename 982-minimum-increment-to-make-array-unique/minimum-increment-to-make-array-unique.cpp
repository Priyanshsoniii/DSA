class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n-1;++i){
            if(nums[i]==nums[i+1]){
                nums[i+1] +=1;
                cnt+=1;
            }
            else if(nums[i]>nums[i+1]){
                cnt+= nums[i]+1 - nums[i+1];
                nums[i+1] = nums[i] + 1;
            }
        }
        return cnt;
    }
};