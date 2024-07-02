class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>vis;
        for(auto x : magazine) vis[x]++;
        for(auto x : ransomNote){
            if(vis[x]<=0) return false;
            vis[x]--;
        } 
        return true;
    }
};