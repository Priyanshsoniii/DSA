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
    int heightBT(TreeNode* root){
        if(root==NULL)return 0;
        int lh = heightBT(root->left);
        int rh = heightBT(root->right);
        return max(lh,rh)+1;
    }
    void solve(TreeNode* root,bool& ans){
        if(root==NULL)return;
        if(abs(heightBT(root->left)-heightBT(root->right))>1) ans = false;
        solve(root->left,ans);
        solve(root->right,ans);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};