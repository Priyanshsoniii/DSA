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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<pair<TreeNode*,int>>q;
        int height = 0;
        q.push({root,height});
        vector<vector<int>>levelOrder;
        vector<int>temp;
        while(!q.empty()){
            TreeNode* curNode = q.front().first;
            int curHeight = q.front().second;
            q.pop();
            if(curNode->left)
            q.push({curNode->left,curHeight+1});
            if(curNode->right)
            q.push({curNode->right,curHeight+1});
            if(height!=curHeight){
                height = curHeight;
                levelOrder.push_back(temp);
                temp.clear();
            }
            temp.push_back(curNode->val);
        }
        levelOrder.push_back(temp);
        temp.clear();
        for(auto x : levelOrder){
            temp.push_back(x.back());
        }
        return temp;
    }
};