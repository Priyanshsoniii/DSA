class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int N = vals.size();
        vector<int>adj[N];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>temp = vals;
        for(int i=0;i<N;++i){
            sort(adj[i].begin(),adj[i].end(),[&](int a,int b){
                return temp[a]>temp[b];
            });
        }
        int csum=0,msum=INT_MIN;
        for(int i=0;i<N;++i){
            int tk = k;
            csum+=vals[i];
            for(auto it : adj[i]){
                if(tk==0) break;
                if(vals[it]>0)
                csum+=vals[it];
                tk--;
            }
            msum = max(msum,csum);
            csum = 0;
        }
        return msum;
    }
};