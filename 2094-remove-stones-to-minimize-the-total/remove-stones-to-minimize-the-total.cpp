class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto x : piles){
            pq.push(x);
        }
        int ele = 0;
        while(k--){
            ele = pq.top();
            pq.pop();
            if(ele%2!=0) ele+=1;
            ele /=2;
            pq.push(ele);
        }
        ele = 0;
        while(!pq.empty()){
            ele += pq.top();
            pq.pop();
        }
        return ele;
    }
};