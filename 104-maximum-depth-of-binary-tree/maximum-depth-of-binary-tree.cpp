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
    int solve(TreeNode*root,int height){
        if(root==NULL) return 0;
        int lDepth = 1 + solve(root->left,height);
        int rDepth = 1 + solve(root->right,height);

        return max(lDepth,rDepth);
    }
    int maxDepth(TreeNode* root) {
        return solve(root,0);
    }
};