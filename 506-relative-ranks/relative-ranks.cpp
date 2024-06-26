class Solution {
public:
    string toString(int x){
        string res = "";
        while(x){
            res += x%10 + '0';
            x/=10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans;
        priority_queue<int>pq;
        for(auto x : score) pq.push(x);
        unordered_map<int,int>mp;
        int i = 1;
        while(!pq.empty()){
            mp[pq.top()] = i++;
            pq.pop(); 
        }
        for(auto x : score){
            if(mp[x]==1){
                ans.push_back("Gold Medal");
            }
            else if(mp[x]==2){
                ans.push_back("Silver Medal");
            }
            else if(mp[x]==3){
                ans.push_back("Bronze Medal");
            }
            else{
                 string temp = toString(mp[x]);
                 ans.push_back(temp);
            }
        }
        return ans;
    }
};