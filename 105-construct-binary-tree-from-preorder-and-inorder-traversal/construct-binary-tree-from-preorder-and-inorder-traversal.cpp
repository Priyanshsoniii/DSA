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
    int findPos(int val,vector<int>&inorder,int start,int end){
        for(int i=start;i<=end;++i){
            if(inorder[i]==val) return i;
        }
        return 0;
    }
    TreeNode* constructTree(vector<int>&preorder,vector<int>&inorder,int start,int end,int &index){
        if(start>end) return NULL;
        int val = preorder[index];
        index++;
        
        TreeNode* node = new TreeNode(val);
        if(start==end) return node;

        int pos = findPos(val,inorder,start,end);
        node->left = constructTree(preorder,inorder,start,pos-1,index);
        node->right = constructTree(preorder,inorder,pos+1,end,index);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int end = preorder.size()-1;
        int index=0;
        return constructTree(preorder,inorder,0,end,index);
    }
};