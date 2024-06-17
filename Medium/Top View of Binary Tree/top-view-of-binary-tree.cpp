//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
     void preOrder(Node* root,int initialLevel,int nodeHeight,vector<pair<pair<int,int>,int>> & minHeap){
        if(root==NULL) return;
        minHeap.push_back({{initialLevel,nodeHeight},root->data});
        if(root->left)
        preOrder(root->left,initialLevel-1,nodeHeight+1,minHeap);
        if(root->right)
        preOrder(root->right,initialLevel+1,nodeHeight+1,minHeap);
    }
    static bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
        if(a.first.first==b.first.first){
          //  if(a.first.second==b.first.second) return a.second<b.second;
            return a.first.second<b.first.second;
        }
        return a.first.first<b.first.first;
    }
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
         vector<int> ans;
        int initialLevel = 0;
        vector<pair<pair<int,int>,int>>minHeap;
        preOrder(root,0,0,minHeap);
        sort(minHeap.begin(),minHeap.end(),comp);
        vector<int>temp;
        int i=0;
        auto node = minHeap[i];
        int levelIndex = node.first.first;
        int height = node.first.second;
        int value = node.second;
        temp.push_back(value);
        i++;
        while(i<minHeap.size()){
           auto node = minHeap[i];
            if(levelIndex!=node.first.first){
                levelIndex = node.first.first;
               // sort(temp.begin(),temp.end(),greater<int>());
                ans.push_back(temp[0]);
                temp.clear();
            }
            
            value = node.second;
            temp.push_back(value);
           i++;
        }
         //sort(temp.begin(),temp.end(),greater<int>());
        ans.push_back(temp[0]);
        return ans;   
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends