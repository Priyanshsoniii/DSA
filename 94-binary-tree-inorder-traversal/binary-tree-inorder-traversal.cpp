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
void inOrder(TreeNode* root,vector<int>&temp){
        if(root==NULL) return;
        inOrder(root->left,temp);
        temp.push_back(root->val);
        inOrder(root->right,temp);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>temp;
        inOrder(root,temp);
        return temp;
    }
};