class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x : nums) pq.push(x);
        vector<int>result(nums.size());
        int i=0,ele1=0,ele2=0;
        while(!pq.empty()){
            ele1 = pq.top();
            pq.pop();
            if(pq.size()>0)
            ele2 = pq.top();
            pq.pop();
            result[i++] = ele2;
            result[i++] = ele1;
        }
        return result;
    }
};