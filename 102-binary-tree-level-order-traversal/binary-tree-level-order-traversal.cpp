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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh = 1 + height(root->left);
        int rh = 1 + height(root->right);
        return max(lh,rh);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int h = height(root);
        vector<vector<int>>result(h);
        if(root==NULL) return result;
        while(!q.empty()){
            auto ele = q.front();
            int val = ele.first->val;
            int value = ele.first->val;
            int valLevel = ele.second;
            result[valLevel].push_back(value);
            q.pop();
            if(ele.first->left!=NULL)
            q.push({ele.first->left,valLevel+1});
            if(ele.first->right!=NULL)
            q.push({ele.first->right,valLevel+1});
        }
        return result;
    }
};