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
   TreeNode* par=NULL;
void solve(TreeNode *&root, int key)
{
    if (root == NULL)
        return;
    if (root->val > key) {solve(root->left, key);}
    else if (root->val < key) {solve(root->right, key);}
    else if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
            return;
        }
        else if ((root->left == NULL && root->right != NULL) || (root->right ==             NULL && root->left != NULL))
        {
            if (root->left == NULL)
            {
                root = root->right;
                cout << "meo";
            }
            else
            {
                root = root->left;
                cout << "left" << root->val;
            }
            return;
        }
        else if(root->left!=NULL&&root->right!=NULL){
            cout<<root->val<<endl;
            TreeNode *keyNode = root->right;
            while (keyNode->left != NULL)
            {
                par=keyNode;
                keyNode = keyNode->left;
            }
            root->val = keyNode->val;
            //cout<<par->val<<endl;
            if(root->right==keyNode)
            {
                root->right=keyNode->right;
                //root->right=NULL;
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