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
TreeNode* constructBST(TreeNode* root,int val){
        TreeNode* newNode = new TreeNode(val);
        if(root==NULL){
            return newNode;
        }
        if(root->val>val){
            root->left = constructBST(root->left,val);
        }
        else root->right = constructBST(root->right,val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = constructBST(root,val);
        return root;
    }
};