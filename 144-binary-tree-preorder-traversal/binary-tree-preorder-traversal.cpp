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
    // void preOrder(TreeNode* root,vector<int>&temp){
    //     if(root==NULL) return;
    //     temp.push_back(root->val);
    //     preOrder(root->left,temp);
    //     preOrder(root->right,temp);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        // vector<int>temp;
        // preOrder(root,temp);
        // return temp;
        stack<TreeNode*>stk;
        stk.push(root);
        vector<int> ans;
        
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            if(node->right!=NULL)
            stk.push(node->right);
            if(node->left!=NULL)
            stk.push(node->left);
        }
        return ans;
    }
};