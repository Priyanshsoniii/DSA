//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        sort(nums.begin(),nums.end());
        priority_queue<pair<int,int>>pq;
        int ele = nums[0];
        int eleFreq = 0;
        int len = nums.size();
        for(auto x : nums){
           if(ele==x){
                eleFreq++;
           }
           else{
               pq.push({eleFreq,ele});
               eleFreq = 1;
               ele = x;
           }
        }
        pq.push({eleFreq,nums[len-1]});
        vector<int>result;
        while(k--){
            int pqTop = pq.top().second;
            result.push_back(pqTop);
            pq.pop();
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends