class Solution {
public:
    void dfs(int srcNode,int endNode,vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>temp){
        for(auto nbr : graph[srcNode]){
            temp.push_back(nbr);
            if(nbr!=endNode){
                dfs(nbr,endNode,graph,ans,temp);
            }
            else{
              ans.push_back(temp);
            }
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int V = graph.size();
        vector<int>temp;
        temp.push_back(0);
        dfs(0,V-1,graph,ans,temp);
        return ans;
    }
};