class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>deg;
        int center = -1,maxFreq=0;
        for(auto it : edges){
            deg[it[0]]++;
            deg[it[1]]++;
            if(maxFreq<deg[it[0]]){
                maxFreq = deg[it[0]];
                center = it[0];
            }
            if(maxFreq<deg[it[1]]){
                maxFreq = deg[it[1]];
                center = it[1];
            }
        }
        return center;
    }
};