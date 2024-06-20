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
    void inOrder(TreeNode* root,unordered_map<int,bool>&vis,bool &ans,int k){
        if(root==NULL) return;
        if(vis[k-(root->val)]==true){
            ans = true;
            return;
        }
        vis[root->val] = true;
        inOrder(root->left,vis,ans,k);
        inOrder(root->right,vis,ans,k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool>vis;
        bool ans = false;
        inOrder(root,vis,ans,k);
        return ans;
    }
};