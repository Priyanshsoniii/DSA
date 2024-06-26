class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto x : nums){
            pq.push(x);
        }
        int ele1 = pq.top();
        pq.pop();
        int ele2 = pq.top();
        return (ele1-1)*(ele2-1);
    }
};