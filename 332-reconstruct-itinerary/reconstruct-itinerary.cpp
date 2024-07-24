class Solution {
public:

    void dfs(int i, vector<int>adj[],vector<int>&ans){
        for(auto &nbr : adj[i]){
            if(nbr!=-1){
                int temp = nbr;
                nbr = -1;
                dfs(temp,adj,ans);
            }
        }
       ans.push_back(i);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {  
        sort(tickets.begin(),tickets.end());
        vector<string>dest;
        unordered_map<string,bool>vis;
        for(auto it : tickets){
            string a,b;
            a = it[0];
            b = it[1];
            if(vis[a]==false && a!="JFK"){
                dest.push_back(a);
                vis[a] = true;
            }
            if(vis[b]==false && b!="JFK"){
                dest.push_back(b);
                vis[b] = true;
            }
        }
       //sort(dest.begin(),dest.end());
        dest.insert(dest.begin(),"JFK");
        unordered_map<string,int>mpp;
        unordered_map<int,string>mp1;
        int num = 0;
        for(auto it : dest){
            mpp[it] = num;
            mp1[num] = it;
            num++;
        } 
        int n = dest.size();
        vector<int>adj[n];
        for(auto it : tickets){
            string a,b;
            a = it[0];
            b = it[1];
            adj[mpp[a]].push_back(mpp[b]);
        }
        vector<int>ans;
        dfs(0,adj,ans);
        vector<string>res;
        for(auto it : ans){
            res.push_back(mp1[it]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};