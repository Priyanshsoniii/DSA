//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findCeil(Node* root, int input);

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int x;
        cin >> x;
        Node* root = buildTree(s);
        cout << findCeil(root, x) << endl;
    }
    return 1;
}

// } Driver Code Ends


// User function Template for C++

// Function to return the ceil of given number in BST.
void solve(Node* root,int input,int& cur,int &curMin){
    if(root==NULL)return;
    if(root->data>=input){
        if(root->data==input){
            cur = root->data;
            curMin = -1;
            return;
        }
        else if(cur!=input){
            //root->data>input
            curMin = min(curMin,root->data);
        }
    }
    if(root->left)
    solve(root->left,input,cur,curMin);
    if(root->right)
    solve(root->right,input,cur,curMin);
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int cur = -1;
    int curMin = INT_MAX;
    solve(root,input,cur,curMin);
    if(curMin==-1) return cur;
    return curMin==INT_MAX?-1:curMin;
    // Your code here
}