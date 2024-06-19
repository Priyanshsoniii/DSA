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
void solve(TreeNode *&root, int key)
{
    if (root == NULL) return;
    if (root->val > key) solve(root->left, key);
    else if (root->val < key) solve(root->right, key);
    else if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL) root = NULL;
        else if ((root->left == NULL && root->right != NULL) || (root->right ==NULL && root->left != NULL))
        {
            if (root->left == NULL) root = root->right; 
            else root = root->left;
        }
        else if(root->left!=NULL&&root->right!=NULL){
            TreeNode *keyNode = root->right;
            TreeNode* par = NULL;
            while (keyNode->left != NULL)
            {
                par=keyNode;
                keyNode = keyNode->left;
            }
            root->val = keyNode->val;
            if(root->right==keyNode)
            {
                root->right=keyNode->right;
            }
            else
            {
                par->left=keyNode->right;
            }
        }
    }
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        solve(root,key);
        return root;
    }
};