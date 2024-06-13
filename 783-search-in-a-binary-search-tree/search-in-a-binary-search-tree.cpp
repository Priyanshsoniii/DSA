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
    TreeNode* search(TreeNode* root, int val){
        if(root==NULL) return NULL;
        if(root->val==val) return root;
        else if(val<root->val) return search(root->left,val);
        else return search(root->right,val);
        return root;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = NULL;
        node = search(root,val);
        return node;
    }
};