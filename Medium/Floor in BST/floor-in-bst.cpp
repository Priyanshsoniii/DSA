//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    void solve(Node* root,int input,int& cur,int &curMAX){
    if(root==NULL)return;
    if(root->data<=input){
        if(root->data==input){
            cur = root->data;
            curMAX = -1;
            return;
        }
        else if(cur!=input){
            //root->data>input
            curMAX = max(curMAX,root->data);
        }
    }
    if(root->left)
    solve(root->left,input,cur,curMAX);
    if(root->right)
    solve(root->right,input,cur,curMAX);
}
int floor(Node* root, int input) {
    if (root == NULL) return -1;
    int cur = -1;
    int curMAX = INT_MIN;
    solve(root,input,cur,curMAX);
    if(curMAX==-1) return cur;
    return curMAX==INT_MIN?-1:curMAX;
    // Your code here
}
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends