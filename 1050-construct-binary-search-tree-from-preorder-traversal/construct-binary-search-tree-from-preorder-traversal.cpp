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
        if(root == NULL){
            return newNode;
        }
        else if(val>root->val){
                root->right = constructBST(root->right,val);
        }
        else{
                root->left =  constructBST(root->left,val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = NULL;
       for(auto ele : preorder){
            root = constructBST(root,ele);
       }
       return root;
    }
};