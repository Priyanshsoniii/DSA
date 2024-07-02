class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int size = nums.size();
       int ele = nums[0];
       int eleFreq = 1;
       int flag = -1;
       int cnt = 1;
       for(int i=1;i<size;++i){
            if(nums[i]!=ele){
                if(flag!=-1){
                    nums[flag] = nums[i];
                    flag++;
                    cnt++;
                    ele = nums[i];
                    eleFreq = 1;
                }
                else{
                    ele = nums[i];
                    eleFreq = 1;
                    cnt++;
                }
            }
            else{
                if(flag==-1 && eleFreq==2){
                    flag = i;
                    eleFreq++;
                }
                else{
                    eleFreq++;
                    if(flag!=-1 && eleFreq<=2){
                        nums[flag] = nums[i];
                        flag++;
                        cnt++;
                    }
                    if(flag==-1) cnt++;
                    
                }
            }
       }

       return cnt;
    }
};