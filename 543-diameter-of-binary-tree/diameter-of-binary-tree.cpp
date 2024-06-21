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
   
    int height(TreeNode*root){
        if(root==NULL) return 0;
        int lDepth = 1 + height(root->left);
        int rDepth = 1 + height(root->right);
        return max(lDepth,rDepth);
    }
    void solve(TreeNode* root,int &d){
        if(root==NULL) return;
         int curHeight = height(root->left) + height(root->right);
         d = max(d,curHeight);
         solve(root->left,d);
         solve(root->right,d);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        solve(root,d);
        return d;
    }
};