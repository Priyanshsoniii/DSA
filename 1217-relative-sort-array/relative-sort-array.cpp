class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       //arr2 ele are distinct 
       //arr1 contain all arr2 ele
       //sort arr1 that  
       map<int,int>mp;
       for(auto ele : arr1){
            mp[ele]++; 
       }
       int i=0;
       for(auto ele : arr2){
            while(mp[ele]!=0){
                arr1[i++] = ele;
                mp[ele]--;
            }
       }

       for(auto it : mp){
         while((it.second)!=0){
            arr1[i++] = (it.first);
            it.second--;
         }
       }

       return arr1;
    }
};