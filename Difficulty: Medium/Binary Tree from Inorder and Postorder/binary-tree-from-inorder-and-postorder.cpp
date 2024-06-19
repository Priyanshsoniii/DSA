//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    int findIndex(int in[],int start,int end,int value){
        for(int i=start;i<=end;++i)
            if(in[i]==value) return i;
            
        return 0;
    }
    Node* constructBT(int in[],int post[],int start,int end,int &index){
        if(start>end) return NULL;
        int value = post[index];
        index--;
        Node* newNode = new Node(value);
        if(start==end) return newNode;
        int pos = findIndex(in,start,end,value);
        newNode->right = constructBT(in,post,pos+1,end,index);
        newNode->left = constructBT(in,post,start,pos-1,index);
        return newNode;
    }
    Node *buildTree(int n, int in[], int post[]) {
        Node* root = NULL;
        int index=n-1;
        root = constructBT(in,post,0,n-1,index);
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends