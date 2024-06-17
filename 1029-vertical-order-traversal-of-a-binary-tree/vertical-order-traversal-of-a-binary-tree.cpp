/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* root,int initialLevel,int nodeHeight,vector<pair<pair<int,int>,int>> & minHeap){
        if(root==NULL) return;
        minHeap.push_back({{initialLevel,nodeHeight},root->val});
        if(root->left)
        preOrder(root->left,initialLevel-1,nodeHeight+1,minHeap);
        if(root->right)
        preOrder(root->right,initialLevel+1,nodeHeight+1,minHeap);
    }
    static bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
        if(a.first.first==b.first.first){
            if(a.first.second==b.first.second) return a.second<b.second;
            return a.first.second<b.first.second;
        }
        return a.first.first<b.first.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        int initialLevel = 0;
        vector<pair<pair<int,int>,int>>minHeap;
        preOrder(root,0,0,minHeap);
        sort(minHeap.begin(),minHeap.end(),comp);
        vector<int>temp;
        int i=0;
        auto node = minHeap[i];
        int levelIndex = node.first.first;
        int height = node.first.second;
        int value = node.second;
        temp.push_back(value);
        i++;
        while(i<minHeap.size()){
           auto node = minHeap[i];
            if(levelIndex!=node.first.first){
                levelIndex = node.first.first;
               // sort(temp.begin(),temp.end(),greater<int>());
                ans.push_back(temp);
                temp.clear();
            }
            
            value = node.second;
            temp.push_back(value);
           i++;
        }
         //sort(temp.begin(),temp.end(),greater<int>());
        ans.push_back(temp);
        return ans;   
    }
};