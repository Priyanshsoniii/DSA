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
    int findIndex(vector<int>&inorder,int val,int start,int end){
        int len = inorder.size();
        for(int i=start;i<=end;++i) if(inorder[i]==val) return i;
        return 0;
    }
    TreeNode* constructBT(vector<int>&inorder,vector<int>&postorder,int start,int end,int &index){
        if(start>end) return NULL;
        int value = postorder[index];
        index--;
        TreeNode* newNode = new TreeNode(value);
        if(start==end) return newNode;
        int pos = findIndex(inorder,value,start,end);
        newNode->right = constructBT(inorder,postorder,pos+1,end,index);
        newNode->left = constructBT(inorder,postorder,start,pos-1,index);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        int size = inorder.size();
        int index = size-1;
        root = constructBT(inorder,postorder,0,size-1,index);
        return root;
    }
};