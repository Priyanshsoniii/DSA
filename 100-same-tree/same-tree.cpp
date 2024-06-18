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
    void preOrder(TreeNode* p,TreeNode*q,bool &ans){
        if(p==NULL && q==NULL) return;
        if((p==NULL && q!=NULL)||(p!=NULL && q==NULL)){
            ans = false;
            return;
        }
        if(p->val!=q->val){
            ans = false;
            return;
        }
        preOrder(p->left,q->left,ans);
        preOrder(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = true;
        preOrder(p,q,ans);
        return ans;
    }
};