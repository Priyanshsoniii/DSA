class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int cnt=0;
        // for(int i=0;i<n-1;++i){
        //     if(nums[i]==nums[i+1]){
        //         nums[i+1] +=1;
        //         cnt+=1;
        //     }
        //     else if(nums[i]>nums[i+1]){
        //         cnt+= nums[i]+1 - nums[i+1];
        //         nums[i+1] = nums[i] + 1;
        //     }
        // }
        // return cnt;
        int n = nums.size();
        int maxElement = INT_MIN;

        for(auto x : nums) maxElement = max(maxElement,x);

        vector<int>freqCount(n+maxElement+1,0);

        for(auto x : nums) freqCount[x]++;

        int minIncrement = 0;

        for(int i=0;i<(n+maxElement+1);++i){
            if(freqCount[i]<=1) continue;
            int duplicates = freqCount[i] - 1;
            freqCount[i+1] += duplicates;
            freqCount[i] = 1;
            minIncrement += duplicates;
        }
        return minIncrement;
    }
};